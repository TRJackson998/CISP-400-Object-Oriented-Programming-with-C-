#include "PolygonMatrix.h"

using namespace Matrices;

namespace Graph_lib {

    ///used to map from pixels to Cartesian coordinates and back
    double mapRange(double n, double fromLow, double fromHigh, double toLow, double toHigh) {
        ///old mapRange function

        double result;
        result = ((n-fromLow) / (fromHigh - fromLow)) * (toHigh - toLow) + toLow;
        return result;
    }

    PolygonMatrix::PolygonMatrix(int _xPixels, int _yPixels) : pointMatrix(2,0) {
        ///construct pointMatrix with 2 rows and 0 cols
        ///store xPixels and yPixels for range mapping
        xPixels = _xPixels;
        yPixels = _yPixels;
    }

    void PolygonMatrix::add(Point p) {
        ///add a pixel vertex to the polygon
        ///call the parent add function with Point p
        Polygon::add(p);
        ///use mapRange to map p.x and p.y to Cartesian coordinates
        p.x = mapRange(p.x, 0, xPixels, -xPixels/2, xPixels/2);
        p.y = mapRange(p.y, yPixels, 0, -yPixels/2, yPixels/2);
        ///use addCoordinate to add the mapped x and y values to pointMatrix
        pointMatrix.addCoordinate(p.x, p.y);
    }

    void PolygonMatrix::rotate(double theta) {
        ///rotate polygon by theta radians counter-clockwise
        ///construct a RotationMatrix R, mulitply it by pointMatrix
        RotationMatrix R(theta);
        pointMatrix = R * pointMatrix;
        ///then call updatePixels
        updatePixels();
    }

    void PolygonMatrix::scale(double c) {
        ///Scale the size of the polygon by factor c
        ///construct a ScalingMatrix S, multiply it by pointMatrix
        ScalingMatrix S(c);
        pointMatrix = S * pointMatrix;
        ///then call updatePixels
        updatePixels();
    }

    void PolygonMatrix::translate(double xShift, double yShift) {
        ///shift the polygon by (xShift, yShift) coordinates
        ///construct a TranslationMatrix T, add it to pointMatrix
        TranslationMatrix T(xShift, yShift, pointMatrix.getCols());
        pointMatrix = pointMatrix + T;
        ///then call updatePixels
        updatePixels();
    }

    void PolygonMatrix::updatePixels() {
        ///Loop through each column of point matrix
        for (int c = 0; c < pointMatrix.getCols(); c++) {
            ///map each coordinate to pixels
            Point p;
            p.x = mapRange(pointMatrix(0,c), -xPixels/2, xPixels/2, 0, xPixels);
            p.y = mapRange(pointMatrix(1,c), -yPixels/2, yPixels/2, yPixels, 0);

            //pointMatrix(0,c) = x coordinate;
            //pointMatrix(1, c) = y coordinate;

            ///call Shape::set_point to update each pixel
            //void set_point(int i, Point p) { points[i] = p; }
            Shape::set_point(c, p);
        }        
    }
}