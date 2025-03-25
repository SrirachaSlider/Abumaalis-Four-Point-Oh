//code being tested here
#include <iostream>
#include "ll.h"
#include "particle.h"
#include "particleSystem.h"
#include "/public/colors.h"
#include <string>
using namespace std;

void test() {
	ParticleSystem mySystem;
	//Particle p(1, 1, 1, 1, 1, "test");
	//mySystem.addParticle(p);
	//cout << mySystem.numParticles() << endl;
	cout << "This is where the different functions will be tested, pick a number to try things out\n";
	int choice = -1;
	while (cin) {
		cout << "0. Type '0' to quit\n1. Add a particle to the Particle System (will be added to the tail of the linked list)\n2. Print X and Y position of particle at head\n3. Print X and Y position of particle at tail\n4. Print the X and Y positions of all the particles in the Particle System (linked list print)\n5. Print size of linked list / number of particles\n6. Print number of rows and columns on your screen\n7. Draw all particles\n8. Make all particles move\n";
		cin >> choice;
		if (choice == 0) break;
		else if (choice == 1) {
			cout << "Insert numbers for the X and Y position, the X and Y velocity, and the lifetime for the particle you are adding (will be added to tail of linked list)\nAlso insert the type you want your particle to be (Streamer, Ballistic, or Firework), if you want the particle to behave based on your velocity inputs, just insert anything else for type\n";
			int x = 0, y = 0, xv = 0, yv = 0, lifeTime = 0;
			string type = "none";
			cout << "X and Y position: ";
			cin >> x >> y;
			cout << "X and Y Velocity: ";
			cin >> xv >> yv;
			cout << "Lifetime: ";
			cin >> lifeTime;
			cout << "Type: ";
			cin >> type;
			Particle p(x, y, xv, yv, lifeTime);
			mySystem.addParticle(p);
			cout << "Particle added" << endl;
		}
		else if (choice == 2) {
			if (mySystem.get_head() != nullptr) {
				cout << "Particle at head's X pos: " << mySystem.get_head()->get_data().x << endl;
				cout << "Particle at head's Y pos: " << mySystem.get_head()->get_data().y << endl;
			}
			else cout << "Nothing to print\n";
		}
		else if (choice == 3) {
			if (mySystem.get_tail() != nullptr) {
				cout << "Particle at tail's X pos: " << mySystem.get_tail()->get_data().x << endl;
				cout << "Particle at tail's Y pos: " << mySystem.get_tail()->get_data().y << endl;
			}
			else cout << "Nothing to print\n";
		}
		else if (choice == 4) {
			if (mySystem.numParticles()) {
				cout << "Here are the X and Y position's of all the particles currently in the particle system going from head to tail:\n";
				int counter = 0;
				for (Cell* temp = mySystem.get_head(); temp != nullptr; temp = temp->next) {
					cout << "Particle " << counter << ":\n";
					cout << "X pos: " << temp->get_data().x;
					cout << ", Y pos: " << temp->get_data().y << endl;
					counter++;
				}
			}
			else cout << "Nothing to print\n";
		}
		else if (choice == 5) cout << "The number of particles in the system is: " << mySystem.numParticles() << endl;
		else if (choice == 6) cout << "Rows: " << mySystem.get_rows() + 1 << endl << "Columns: " << mySystem.get_cols() + 1 << endl;
		else if (choice == 7) {
			mySystem.drawParticles();
			movecursor(mySystem.rows, 1);
		}
		else if (choice == 8) {
			mySystem.moveParticles();
			movecursor(mySystem.rows, 1);
		}
		//else if (choice == 8) mySystem.physics();
		else cout << "Invalid input, try again\n";
	}
	show_cursor(true);
}
