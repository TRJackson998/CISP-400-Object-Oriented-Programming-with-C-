#include "calculator.h"

unsigned long long factorial(int n)
{ //returns n!
    if (n == 1) {
        return n;
    }
    else {
        return n * factorial(n-1);
    }
}

double factExp(double x, int n)
{ 
/*
returns {x^n}/{n!}
The factorial in the denominator will overflow after about 20!, so we will not be able to use our factorial function here
Instead, use a for loop to keep the terms small as they are being multiplied
*/
    double total = 1; 
    for (int i = 1; i <= n; i++) {
        total *= (x/i);
    }
    return total;
}

double sin(double x, int nTerms) //present this one
{
/*
Sine can be approximated with a Taylor Series:
sin(x) = x - {x^3}/{3!} + {x^5}/{5!} - {x^7}/{7!} + {x^9}{9!} - ...
The more terms added together the more accurate the approximation is
The parameter nTerms will determine how many terms to generate
Use your factExp function to generate each term
eg the first term is factExp(x, 1), the second term is factExp(x,3), etc
Note the terms alternate positive and negative, ie + - + - ...
*/

    double total = 0;
    int j = 1;
    int neg = -1;
    for (int i = 0; i < nTerms; i++) {
        neg *= -1;
        total += (neg * factExp(x, j));
        j += 2;
    }
    return total;
}

double sqrt(double x, int nTerms)
{
    double next, prev = 1;
    for (int i = 0; i < nTerms; i++) {
        next = prev - ((prev * prev - x) / (2 * prev));
        prev = next;
    }
    return next;
}

double primary()	// Number or �(� Expression �)�
{
    Token t = ts.get();
    switch (t.kind)
    {
    case '(':			       // handle �(�expression �)�
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')')
            error("')' expected");


        ///Look ahead for a fact Token here before returning d
        Token nextOne = ts.get();
        if (nextOne.kind == fact) {
            return factorial(d);
        }
        ///don't forget to put the Token back if it is not fact
        else {
            ts.putback(nextOne);
        }

        return d;	// return the number�s value

    }

    case '-':
        return -primary();

    case number:	// rather than case '8':
    {
        ///Look ahead for a fact Token here before returning t's value
        Token nextOne = ts.get();
        if (nextOne.kind == fact) {
            return factorial(t.value);
        }
        ///don't forget to put the Token back if it is not fact
        else {
            ts.putback(nextOne);
        }
        return t.value;	// return the number�s value

    }

    ///if the token is of type sine, then
    ///call for a new primary
    ///pass that into the sin function
    ///use nTerms = 1000
    case sine:
        return sin(primary(), 1000);
        ///fix me

    ///if the token is of type root, then
    ///call for a new primary
    ///pass that into the sqrt function
    ///use nTerms = 1000
    case root:
        return sqrt(primary(), 1000);
        ///fix me

    default:
        error("primary expected");
    }
}

///The code below this line does not need to be changed at all

double expression()	// read and evaluate: 1   1+2.5   1+2+3.14  etc.
{
    double left = term(); 			// get the Term
    while (true)
    {
        Token t = ts.get();		// get the next token�
        switch (t.kind)  			// � and do the right thing with it
        {
        case '+':
            left += term();
            break;
        case '-':
            left -= term();
            break;
        default:
            ts.putback(t);

            return left;		// return the value of the expression
        }
    }
}
double term()	// exactly like expression(), but for * and  /
{
    double left = primary(); 		// get the Primary
    while (true)
    {
        Token t = ts.get();	// get the next Token
        switch (t.kind)
        {
        case '*':
            left *= primary();
            break;
        case '/':
        {
            double d = primary();
            if  (d==0)
                error("divide by zero");
            left /= d;
            break;
        }
        default:
            ts.putback(t);
            return left;	// return the value
        }
    }
}


void clean_up_mess()
{
    ts.ignore(print);
}


void calculate()
{
    while (cin)
        try
        {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print)
                t=ts.get();	// first discard all �prints�
            if (t.kind == quit)
                return;		// quit
            ts.putback(t);
            cout << result << expression() << endl;
        }
        catch (exception& e)
        {
            cerr << e.what() << endl;		// write error message
            clean_up_mess();		// <<< The tricky part!
        }
}
