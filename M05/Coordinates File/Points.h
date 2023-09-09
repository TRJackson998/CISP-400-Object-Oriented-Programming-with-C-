#ifndef POINTS_H_INCLUDED
#define POINTS_H_INCLUDED

#include "std_lib_facilities.h"

struct Point
{
   int x, y;
};

///Output in the format (x,y), no newline
ostream& operator<<(ostream& os, const Point& p);

///Input in the form (x,y)
///if is fails (!is), return is.  This is necessary for loops later on.
istream& operator>>(istream& is, Point& p);

///true if the (x,y) values match
bool operator==(const Point& p1, const Point& p2);
bool operator!=(const Point& p1, const Point& p2);

///Output a vector of points
///Call the << operator for a Point (above) for each point in the vector
///Separate by newlines
ostream& operator<<(ostream& os, const vector<Point> & points);


#endif // POINTS_H_INCLUDED
