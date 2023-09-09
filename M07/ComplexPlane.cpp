#include "ComplexPlane.h"

void ComplexPlane::draw_lines() const {
    fl_draw_image(buf, 0, 0, xPixels, yPixels);
}

void writePixel(unsigned char* buf, int xPixels, int row,int col, unsigned char r, unsigned char g, unsigned char b) {
    cout << "Bug\n";
}

int countIterations(double re, double im, int maxIterations) {
    complex<double> c(re, im);
    complex<double> z(0.0, 0.0);

    int count = 0;
    while((abs(z) < 2.0) && (count < maxIterations)) {
        z = z*z + c;
        count ++;
    }
    return count;
}

double mapRange(double n, double fromLow, double fromHigh, double toLow, double toHigh) {
    double result;
    result = ((n-fromLow) / (fromHigh - fromLow)) * (toHigh - toLow) + toLow;
    return result;
}

void ComplexPlane::createBuffer() {
    cout << "createBuffer Bug\n";
}