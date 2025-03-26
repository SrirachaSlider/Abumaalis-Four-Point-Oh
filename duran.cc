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
		cout << "Type '0' if you're done.\nType 1 to test drawPoint.\n";
		cin >> selection;
		if (selection == 0) break;
		else if (selection == 1) {
			cout << "Give me X and Y first.\n";
			int myRow = 0, myCol = 0;
			string type = "none";
			cout << "What is X?\n";
			cin >> myRow;
			cout << "And what is Y?\n";
			cin >> myCol;
			cout << RED;
			test.drawPoint(myRow,myCol);
			cout << "\nOooh! It's got a random color, too!\n";
			resetcolor();
		}
		else { 
			cout << "That ain't a real thing. Type a number.\n";
		}
	}
}
