#include "/public/read.h"
#include <iostream>
#include <string>
#include "mohammad.h"
#include "michael.h"
#include "duran.h"
#include "raj.h"
#include "test.h"

using namespace std;

int main () {
	string user;
	while (cin) {
		cout << "Who's program would you like to run? (Type 'done' to quit)\nChoices: Mohammad, Michael, Duran, or Raj\n";
		cin >> user;
		if (user == "Mohammad" or user == "mohammad") {
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
