#include "Lines_window.h"

using namespace Graph_lib;

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	:Window(xy,w,h,title),  
		// construct/initialize the parts of the window:		
   	                              // location	        size          name            action
	next_button(Point(x_max()-150,0), 70, 20, "Next point", cb_next),
	quit_button(Point(x_max()-70,0), 70, 20, "Quit", cb_quit),       // quit button
	next_x(Point(x_max()-310,0), 50, 20, "next x:"),    	          // io boxes
	next_y(Point(x_max()-210,0), 50, 20, "next y:"),
	xy_out(Point(100,0), 100, 20, "current (x,y):"),
    color_menu(Point(x_max()-70, 40), 70, 20, Menu::vertical, "color"),
    cmenu_button(Point(x_max()-80, 30), 80, 20, "color menu", cb_cmenu),
    line_menu(Point(x_max()-70, 120), 70, 20, Menu::vertical, "line"),
    lmenu_button(Point(x_max()-80, 110), 80, 20, "line menu", cb_lmenu)
{
	attach(next_button);		// attach the parts to the window
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);

    color_menu.attach(new Button(Point(0, 0), 0, 0, "red", cb_red));
    color_menu.attach(new Button(Point(0, 0), 0, 0, "blue", cb_blue));
    color_menu.attach(new Button(Point(0, 0), 0, 0, "black", cb_black));
    attach(color_menu);
    color_menu.hide();
    attach(cmenu_button);

    line_menu.attach(new Button(Point(0, 0), 0, 0, "dot", cb_dot));
    line_menu.attach(new Button(Point(0, 0), 0, 0, "dash", cb_dash));
    line_menu.attach(new Button(Point(0, 0), 0, 0, "solid", cb_solid));
    attach(line_menu);
    line_menu.hide();
    attach(lmenu_button);
    

	attach(lines);			// attach the open_polylines to the window
}


void Lines_window::cb_quit(Address, Address pw)
	// Call Lines_window::quit() for the window located at address pw
{
 	reference_to<Lines_window>(pw).quit();	// now call our function
} 

void Lines_window::quit()
{
	// here we can do just about anything with the Lines_window
	hide();	// peculiar FLTK idiom for "get rid of this window"
}


void Lines_window::cb_next(Address, Address pw)
	// Call Lines_window::quit() for the window located at address pw
{
 	reference_to<Lines_window>(pw).next();	// now call our function
} 

// our action for a click ("push") on the next point button

void Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();

	lines.add(Point(x,y));

	// update current position readout:
	stringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());

	redraw();   // now redraw the screen
} 

void Lines_window::cb_red(Address, Address pw)
	// Call Lines_window::quit() for the window located at address pw
{
 	reference_to<Lines_window>(pw).red_pressed();	// now call our function
} 

void Lines_window::cb_blue(Address, Address pw)
	// Call Lines_window::quit() for the window located at address pw
{
 	reference_to<Lines_window>(pw).blue_pressed();	// now call our function
}

void Lines_window::cb_black(Address, Address pw)
	// Call Lines_window::quit() for the window located at address pw
{
 	reference_to<Lines_window>(pw).black_pressed();	// now call our function
}

void Lines_window::cb_dot(Address, Address pw)
	// Call Lines_window::quit() for the window located at address pw
{
 	reference_to<Lines_window>(pw).dot_pressed();	// now call our function
}

void Lines_window::cb_dash(Address, Address pw)
	// Call Lines_window::quit() for the window located at address pw
{
 	reference_to<Lines_window>(pw).dash_pressed();	// now call our function
}

void Lines_window::cb_solid(Address, Address pw)
	// Call Lines_window::quit() for the window located at address pw
{
 	reference_to<Lines_window>(pw).solid_pressed();	// now call our function
}

void Lines_window::cb_cmenu(Address, Address pw)
	// Call Lines_window::quit() for the window located at address pw
{
 	reference_to<Lines_window>(pw).cmenu_pressed();	// now call our function
}

void Lines_window::cb_lmenu(Address, Address pw)
	// Call Lines_window::quit() for the window located at address pw
{
 	reference_to<Lines_window>(pw).lmenu_pressed();	// now call our function
}
