//This is Duran's section (Part D on Milestone 1)
#pragma once
#include <string>
#include "/public/colors.h"
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

class particleGraphics {
	string color;
	int r = 0, g = 0, b = 0;

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
		//resetcolor();
		movecursor(myRow,myCol);
		setbgcolor(r,g,b);
		//setcolor(255,0,0);
		//clearscreen();
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
				movecursor(row,col);
				cout << " ";          
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
};
		
