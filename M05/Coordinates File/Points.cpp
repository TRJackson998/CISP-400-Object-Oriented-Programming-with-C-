#include "Points.h"

///Output in the format (x,y), no newline
ostream& operator<<(ostream& os, const Point& p) {
    os << '(' << p.x << ',' << p.y << ')';
    return os;
}

///Input in the form (x,y)
///if is fails (!is), return is.  This is necessary for loops later on.
istream& operator>>(istream& is, Point& p) {
    if (!is) {
        return is;
    }
    else {
        char opener = '(', comma = ',', closer = ')';
    
        is >> opener;
        if (opener != '(') {
            error("Invalid input.");
        }

        is >> p.x;
        if (cin.fail()) {
            error("Invalid input.");
        }

        is >> comma;
        if (comma != ',') {
            error("Invalid input.");
        }

        is >> p.y;
        if (cin.fail()) {
            error("Invalid input.");
        }

        is >> closer;
        if (closer != ')') {
            error("Invalid input.");
        }

        return is;
    }
}

///true if the (x,y) values match
bool operator==(const Point& p1, const Point& p2) {
    bool equal = true;

    if ((p1.x != p2.x) || (p1.y != p2.y)) {
        equal = false;
    }

    return equal;
}

bool operator!=(const Point& p1, const Point& p2) {
    return !(p1 == p2);
}

///Output a vector of points
///Call the << operator for a Point (above) for each point in the vector
///Separate by newlines
ostream& operator<<(ostream& os, const vector<Point> & points) {
    for (unsigned int i = 0; i < points.size(); i++) {
        os << points.at(i);
        os << endl;
    }
    return os;
}