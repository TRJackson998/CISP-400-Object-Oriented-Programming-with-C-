#include "ZoomWindow.h"

complex<double> toSetCenter(0.0,0.0);

ZoomWindow::ZoomWindow(Point xy, int w, int h, const string& title)
	:Simple_window(xy,w,h,title),
    plane(PLANE_Y_OFFSET, toSetCenter, 1.0, w, h - PLANE_Y_OFFSET),
    next_i(Point(x_max()-400, 0), 70, 20, "next i"),
    next_r(Point(x_max()-275, 0), 70, 20, "next r"),
    next_zoom(Point(x_max()-150, 0), 70, 20, "next z")
    {
        attach(next_i);
        attach(next_r);
        attach(next_zoom);
    }

bool ZoomWindow::wait_for_button() {
    Simple_window::wait_for_button();

    double i, r, zoom;
    string temp, tempi, tempr, tempz;
    tempi = next_i.get_string();
    tempr = next_r.get_string();
    tempz = next_zoom.get_string();

    temp = tempi + " " + tempr + " " + tempz;
    stringstream ss;
    ss << temp;
    ss >> i >> r >> zoom;

    complex<double> center(r, i);

    plane.setCenter(center);
    plane.setZoomLevel(zoom);
    plane.createBuffer();

    return true;

}

double ZoomWindow::getCenter_r() const {
    complex<double> center;
    center = plane.getCenter();
    return center.real();
}
double ZoomWindow::getCenter_i() const {
    complex<double> center;
    center = plane.getCenter();
    return center.imag();
}
double ZoomWindow::getZoom() const {
    return plane.getZoomLevel();
}