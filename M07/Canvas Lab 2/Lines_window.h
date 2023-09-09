#include "Simple_window.h"

struct Lines_window : Graph_lib::Window 	// Lines_window inherits from Window
{
	Lines_window(Point xy, int w, int h, const string& title); // declare constructor
		
private:
	Open_polyline lines;
	Button next_button;		// declare some buttons – type Button
	Button quit_button;
	In_box next_x;			// declare some i/o boxes
	In_box next_y;
	Out_box xy_out;

    Menu color_menu;
    Button cmenu_button;
    Menu line_menu;
    Button lmenu_button;

    void change(Color c) {lines.set_color(c);}
    void changel(Line_style l) {lines.set_style(l);}

    void hide_cmenu() {color_menu.hide(); cmenu_button.show();}
    void red_pressed() {change(Color::red); hide_cmenu();}
    void blue_pressed () {change(Color::blue); hide_cmenu();}
    void black_pressed() {change(Color::black); hide_cmenu();}
    void cmenu_pressed() {cmenu_button.hide(); color_menu.show();}

    void hide_lmenu() {line_menu.hide(); lmenu_button.show();}
    void dot_pressed() {changel(Line_style::dot); hide_lmenu();}
    void dash_pressed() {changel(Line_style::dash); hide_lmenu();}
    void solid_pressed() {changel(Line_style::solid); hide_lmenu();}
    void lmenu_pressed() {lmenu_button.hide(); line_menu.show();}

    void next(); 			// what to do when next_button is pushed
	void quit(); 			// what to do when quit_botton is pushed


    static void cb_red(Address, Address window);
    static void cb_blue(Address, Address window);
    static void cb_black(Address, Address window);
    static void cb_cmenu(Address, Address window);

    static void cb_dot(Address, Address window);
    static void cb_dash(Address, Address window);
    static void cb_solid(Address, Address window);
    static void cb_lmenu(Address, Address window);

	static void cb_next(Address, Address window); 	// callback for next_button
	static void cb_quit(Address, Address window); 	// callback for quit_button
}; 
