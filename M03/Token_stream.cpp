#include "Token_stream.h"

Token Token_stream::get()	 // read a Token from the Token_stream
{
    if (full)
    {
        full=false;    // check if we already have a Token ready
        return buffer;
    }

    char ch;
    cin >> ch;	// note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch)
    {
    case '(':
    case ')':
    case ';':
    case 'q':
    case '+':
    case '-':
    case '*':
    case '/':
    case fact:
        return Token{ch};		// let each character represent itself
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
        cin.putback(ch);		     // put digit back into the input stream
        double val;
        cin >> val;		     // read a floating-point number
        return Token{number,val}; // rather than Token{'8',val}
    }

    ///look for an 's'
    ///if the stream contains 's''i''n', return a sine token
    ///if the stream contains 's''q''r''t', return a root token
    ///else throw a Bad token exception (use error function)
    case 's':
    {
        
        vector<char> str_sine(3);
            //str_sine.at(0) = 's';
            str_sine.at(1) = 'i';
            str_sine.at(2) = 'n';
        vector<char> str_sqrt(4);
            //str_sqrt.at(0) = 's';
            str_sqrt.at(1) = 'q';
            str_sqrt.at(2) = 'r';
            //str_sqrt.at(3) = 't';
        bool found_sine = false, found_sqrt = false;
        
        for (int i = 1; i <= 2; i++) {
            cin >> ch;
            if (ch == str_sine.at(i)) {
                found_sine = true;
            }
            else if (ch != str_sine.at(i)) {
                found_sine = false;
            }
                        
            if (ch == str_sqrt.at(i)) {
                found_sqrt = true;
            }
            else if (ch != str_sqrt.at(i)) {
                found_sqrt = false;
            }          
        }
        if (found_sine) {
            return Token{sine};
        }
        else if (found_sqrt) {
            cin >> ch; //remove the t from input
            return Token{root};
        }
        else {
            error("Bad Token");
        }

        /*
        //ATTEMPT 2
        if (ch == 'i') {
            cin >> ch;
            if (ch == 'n') {
                cin >> ch;
                if (ch == '(') {
                    cin.putback(ch);
                    return Token{sine};
                }
            }
        }
        else if (ch == 'q') {

        }

        
        //ATTEMPT 1
        cin.putback(ch);
        string s;
        cin >> s;
        if (s == "sine") {
            return Token{sine};
        }
        if (s == "sqrt") {
            return Token{root};
        }
        else {
            error("Bad token");
        }
        */
        
    }


    default:
        error("Bad token");
    }
}


void Token_stream::ignore(char c)
// skip characters until we find a c; also discard that c
{
    // first look in buffer:
    if (full && c==buffer.kind)  	// && means and
    {
        full = false;
        return;
    }
    full = false;	// discard the contents of buffer
    // now search input:
    char ch = 0;
    while (cin>>ch)
        if (ch==c)
            return;
}

void Token_stream::putback(Token t)
{
    if (full)
        error("putback() into a full buffer");
    buffer=t;
    full=true;
}
