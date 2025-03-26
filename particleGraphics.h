//This is Duran's section (Part D on Milestone 1)
#pragma once
#include <string>
#include "/public/colors.h"
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <algorithm>
using namespace std;

class particleGraphics {
	string color;
	int r = 0, g = 0, b = 0;

	int iNumberSet(float one) {
		return (int)one;
	}

	int numberRounder(float one){
		return iNumberSet(one + 0.5);
	}

	float fNumberSet(float one){
		if (one > 0) {
			return one - iNumberSet(one);
		}
		else {
			return one - (iNumberSet(one) + 1);
		}
	}

	float rfNumberSet(float one) {
		return 1 - fNumberSet(one);
	}

	public:
	particleGraphics(){
		srand(time(0));
		r = rand() % 255;
		g = rand() % 255;
		b = rand() % 255;
		//auto [myRows, myCols] = get_terminal_size();
		//int rows = myRows -1;
		//int cols = myCols -1;
	}
	/*void set_color(string c){
	  color = c;
	  }
	  string get_color() {
	  return color;
	  }*/
	void drawPoint(int myRow, int myCol) {
		movecursor(myRow,myCol);
		setbgcolor(r,g,b);
		cout << " ";
		cout.flush();
		resetcolor();
	}
	void drawRectangle(int x_one, int x_two, int y_one, int y_two) {
		//assert(x_one < x_two);
		//assert(y_one < y_two);
		if (x_one > x_two) std::swap(x_one, x_two);
		if (y_one > y_two) std::swap(y_one, y_two);
		resetcolor();
		setbgcolor(r,g,b);
		/*for (int row = x_one; row <= x_two; row++) {
		  for (int col = y_one * scale; col <= y_two * scale; col++) {
		  if (row == x_one || row == x_two || col == y_one || col == y_two) {
		  movecursor(row, col);
		  cout << " ";          
		  }
		  }
		  }*/
		double scale = 2;
		for (int col = y_one; col <= y_two; col++) {   // Outer loop = Y (vertical)
			for (int row = x_one * scale; row <= x_two * scale; row++) { // Inner loop = X (horizontal)
				if (col == y_one || col == y_two || row == x_one * scale || row == x_two * scale) {
					movecursor(col, row);  // Now properly maps x → horizontal, y → vertical
					cout << " ";
				}
			}
		}

		resetcolor();
		cout.flush();
	}
	void drawVertLine(int y_one, int y_two, int x) {
		// add to this!
	}
	void drawHorizLine(int x_one, int x_two, int y) {
		// add to this!
	}
	void drawLine(int x_one, int x_two, int y_one, int y_two) {
		/*int steep = abs(y_two - y_one) > abs(x_two - x_one);
		  if (steep) {
		  swap (x_one, y_one);
		  swap (x_two, y_two);
		  }
		  if (x_one > x_two) {
		  swap (x_one, y_two);
		  swap (y_one, x_two);
		  }
		  float dx = x_two - x_one;
		  float dy = y_two - y_one;
		  float gradient = dy / dx;
		  if (dx == 0.0){
		  gradient = 1;
		  }

		  int x_firstpixel = x_one;
		  int x_secondpixel = x_two;
		  float intersect_Y = y_one;

		  if (steep) {
		  int one;
		  for (one = x_firstpixel; one <= x_secondpixel; one++) {
		  drawPoint(iNumberSet(intersect_Y), rfNumberSet(intersect_Y));	
		  drawPoint(iNumberSet(intersect_Y) - 1, fNumberSet(intersect_Y));
		  intersect_Y += gradient;
		  }
		  }
		  else {
		  int one;
		  for (one = x_firstpixel; one <= x_secondpixel; one++) {
		  drawPoint(iNumberSet(intersect_Y), rfNumberSet(intersect_Y));	
		  drawPoint(iNumberSet(intersect_Y) - 1, fNumberSet(intersect_Y));
		  intersect_Y += gradient;
		  }
		  }*/
		if (x_one > x_two) std::swap(x_one, x_two);
		if (y_one > y_two) std::swap(y_one, y_two);

		// Scale X-coordinates to maintain 2:1 aspect ratio
		x_one *= 2;
		x_two *= 2;

		int dx = x_two - x_one;
		int dy = y_two - y_one;
		int sx = (dx > 0) ? 1 : -1;
		int sy = (dy > 0) ? 1 : -1;
		dx = abs(dx);
		dy = abs(dy);

		int err = (dx > dy ? dx : -dy) / 2;
		int e2;

		while (true) {
			movecursor(y_one, x_one);  // Use (y, x) to match terminal row/column order
			cout << " ";  

			if (x_one == x_two && y_one == y_two) break;

			e2 = err;
			if (e2 > -dx) { err -= dy; x_one += sx; }  // Move in x direction
			if (e2 < dy) { err += dx; y_one += sy; }  // Move in y direction
		}

		cout.flush();
	}

};

