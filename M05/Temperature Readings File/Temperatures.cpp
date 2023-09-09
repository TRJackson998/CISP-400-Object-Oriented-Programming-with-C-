#include "Temperatures.h"

istream& operator>>(istream& is, Reading& r)
// read a temperature reading from is into r
// format: ( 3 4 9.7 )
// check format, but don’t bother with data validity
{
    char ch1;
    if (is>>ch1 && ch1!='(')
    { // could it be a Reading?
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }
    char ch2;
    int d;
    int h;
    double t;
    is >> d >> h >> t >> ch2;
    if (!is || ch2!=')') error("bad reading"); // messed-up reading
    r.day = d;
    r.hour = h;
    r.temperature = t;
    return is;
}

istream& operator>>(istream& is, Month& m) // format: { month feb . . . }
{
    char ch = 0;
    if (is >> ch && ch!='{')
    {
        is.unget();
        is.clear(ios_base::failbit); // we failed to read a Month
        return is;
    }
    string month_marker;
    string mm;
    is >> month_marker >> mm;
    if (!is || month_marker!="month") error("bad start of month");
    m.month = month_to_int(mm);
    int duplicates = 0;
    int invalids = 0;
    for (Reading r; is >> r; )
    {
        if (is_valid(r))
        {
            if (m.days[r.day].hours[r.hour] != not_a_reading)
                ++duplicates;
            m.days[r.day].hours[r.hour] = r.temperature;
        }
        else
            ++invalids;
    }
    if (invalids) error("invalid readings in month",invalids);
    if (duplicates) error("duplicate readings in month", duplicates);
    end_of_loop(is,'}',"bad end of month");
    return is;
}


istream& operator>>(istream& is, Year& y)
// read a year from is into y
// format: { year 1972 . . . }
{
    char ch;
    is >> ch;
    if (ch!='{')
    {
        is.unget();
        is.clear(ios::failbit);
        return is;
    }
    string year_marker;
    int yy;
    is >> year_marker >> yy;
    if (!is || year_marker!="year") error("bad start of year");
    y.year = yy;
    while(true)
    {
        Month m; // get a clean m each time around
        if(!(is >> m)) break;
        y.months[m.month] = m;
    }
    end_of_loop(is,'}',"bad end of year");
    return is;
}

int month_to_int(string s)
// is s the name of a month? If so return its index [0:11] otherwise –1
{
    for (int i=0; i<12; ++i) if (month_input_tbl[i]==s) return i;
    return not_a_month;
}

bool is_valid(const Reading& r)
// a rough test
{
    if (r.day<1 || 31<r.day) return false;
    if (r.hour<0 || 23<r.hour) return false;
    if (r.temperature<implausible_min|| implausible_max<r.temperature) return false;
    return true;
}

void end_of_loop(istream& ist, char term, const string& message)
{
    if (ist.fail())
    { // use term as terminator and/or separator
        ist.clear();
        char ch;
        if (ist >> ch  &&  ch == term) return; // all is fine
        error(message);
    }
}

string int_to_month(int i) {
    return month_print_tbl[i];
}

///Print each reading for every month, day, and hour within Year& y
///Use a triple nested for loop for 12 months, 31 days per month, and 24 hours per day
///print each reading in the following format:
///set os precision to 2, fixed point
///field width 12, separated by '|'
///         year|       Month|         day|        hour|     reading|
///example:
///         2018|     January|          30|           7|       62.12|
///The member access operator . is your friend
///string int_to_month(int i)   to convert a month index to a printable string
///only print if the reading != not_a_reading
ostream& operator<<(ostream& os, Year& y) {
    for (int i = 0; i < 12; i++) {
        for (int j = 1; j < 32; j++) {
            for (int k = 0; k < 24; k++) {
                if (y.months[i].days[j].hours[k] != not_a_reading)
                os << fixed << setprecision(2)
                << setw(12) << y.year                       << "|"
                << setw(12) << int_to_month(i) << "|"
                << setw(12) << j                            << "|"
                << setw(12) << k                            << "|"
                << setw(12) << y.months[i].days[j].hours[k] << "|"
                << endl;
            }
        }
    }

    return os;
}