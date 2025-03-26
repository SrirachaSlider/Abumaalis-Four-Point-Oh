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
			assert(x_one < x_two);
			assert(y_one < y_two);
			resetcolor();
			setbgcolor(r,g,b);
				for (int row = x_one; row <= x_two; row++) {
					for (int col = y_one; col <= y_two; col++) {
						if (row == x_one || row == x_two || col == y_one || col == y_two) {
							movecursor(row,col);
							cout << " ";          
						}
					}
				}
			cout.flush();
		}
		void drawVertLine(int y_one, int y_two, int x) {
		// add to this!
		}
		void drawHorizLine(int x_one, int x_two, int y) {
		// add to this!
		}
		void drawLine (int x_one, int x_two, int y_one, int y_two) {
			int steep = abs(y_two - y_one) > abs(x_two - x_one);
			if (steep) {
				swap (x_one, y_one);
				swap (x_two, y_two);
			}
			else if (x_one > x_two) {
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
			}
		}

};
		
