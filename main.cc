#include "/public/read.h"
#include <iostream>
#include <string>
#include "mohammad.h"
#include "michael.h"
#include "duran.h"
#include "raj.h"
#include "test.h"
#include "/public/colors.h"

using namespace std;

int main () {
	string user;
	while (cin) {
		cout << "Who's program would you like to run? (Type 'done' to quit or 'test' to test)\nChoices: Mohammad, Michael, Duran, or Raj\n";
		cin >> user;
		if (user == "Mohammad" or user == "mohammad") {
			//const auto [rows,cols] = get_terminal_size();
			//cout << "ROWS: " << rows << " COLS: " << cols << endl;
			mohammad();
		}
		else if (user == "Michael" or user == "michael") {
			michael();
		}
		else if (user == "Duran" or user == "duran") {
			duran();
		}
		else if (user == "Raj" or user == "raj") {
			raj();
		}
		else if (user == "test") {
			test();
		}
		else if (user == "done" or user == "Done") break;
		else {
			cout << "Invalid Input, Try Again\n";
			continue;
		}
	}
}
