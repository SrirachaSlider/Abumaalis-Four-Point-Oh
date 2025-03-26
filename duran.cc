#include <iostream>
#include "duran.h"
#include "ll.h"
#include "particle.h"
#include "particleSystem.h"
#include "particleGraphics.h"
#include "/public/colors.h"
using namespace std;

void duran() {
	particleGraphics test;
	clearscreen();
	cout << "Wanna spice things up? Enter a number.\n";
	int selection = -1;
	while (cin) {
		cout << "Type '0' if you're done.\nType '1' to test drawPoint.\nType '2' to test drawRectangle.";
		cin >> selection;
		if (selection == 0) {
			clearscreen();
			break;
		}
		else if (selection == 1) {
			cout << "Give me X and Y first.\n";
			int myRow = 0, myCol = 0;
			string type = "none";
			cout << "What is X?\n";
			cin >> myRow;
			cout << "And what is Y?\n";
			cin >> myCol;
			cout << RED;
			clearscreen();
			test.drawPoint(myRow,myCol);
			cout << "\nOooh! It's got a random color, too!\n";
			resetcolor();
		}
		else if (selection == 2) {
			cout << "I'm gonna need 4 numbers from you. Okay?\n";
			int x_one = 0, x_two = 0, y_one = 0, y_two = 0;
			string type = "none";
				cout << "First number?\n";
				cin >> x_one;
				cout << "Second number? Be sure it's bigger than the first!\n";
				cin >> x_two;
				cout << "Third number?\n";
				cin >> y_one;
				cout << "Last number? Be sure it's bigger than the third!\n";
				cin >> y_two;
				cout << RED;
				clearscreen();
				test.drawRectangle(x_one,x_two,y_one,y_two);
				cout << "\nMan, that's a...rectangle, alright.\n";
				resetcolor();
		}
		else { 
			cout << "That ain't a real thing. Type a number.\n";
		}
	}
}
