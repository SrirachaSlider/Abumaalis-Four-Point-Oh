//code being tested here
#include <iostream>
#include "ll.h"
#include "particle.h"
#include "particleSystem.h"
using namespace std;

void test() {
	ParticleSystem mySystem;
	//Particle p(1, 1, 1, 1, 1, "test");
	//mySystem.addParticle(p);
	//cout << mySystem.numParticles() << endl;
	cout << "This is where the different functions will be tested, pick a number to try things out\n(Note that the number 'associated' with each particle has nothing to do with the particles or the program at all,\nit is just there to show that the linked list of particles is working.)\n";
	int choice = -1;
	while (cin) {
		cout << "0. Type '0' to quit\n1. Add a particle to the Particle System (will be added to the tail of the linked list)\n2. Print X and Y position of particle at head\n3. Print X and Y pos of particle at tail\n4. Print the X and Y positions of all the particles in the Particle System (linked list print)\n5. Print size of linked list / number of particles\n6. Print number of rows and columns on your screen\n";
		cin >> choice;
		if (choice == 0) break;
		else if (choice == 1) {
			cout << "Insert numbers for the X and Y position, the X and Y velocity, and the lifetime for the particle you are adding (will be added to the tail of linked list)\n";
			int x = 0, y = 0, xv = 0, yv = 0, lifeTime = 0;
			cout << "X and Y position: ";
			cin >> x >> y;
			cout << "X and Y Velocity: ";
			cin >> xv >> yv;
			cout << "Lifetime: ";
			cin >> lifeTime;
			Particle p(x, y, xv, yv, lifeTime);
			mySystem.addParticle(p);
			cout << "Particle added" << endl;
		}
		else if (choice == 2) {
			if (mySystem.get_head() != nullptr) {
				cout << "Particle at head's X pos: " << mySystem.get_head()->get_data().positionX << endl;
				cout << "Particle at head's Y pos: " << mySystem.get_head()->get_data().positionY << endl;
			}
			else cout << "Nothing to print\n";
		}
		else if (choice == 3) {
			if (mySystem.get_tail() != nullptr) {
				cout << "Particle at tail's X pos: " << mySystem.get_tail()->get_data().positionX << endl;
				cout << "Particle at tail's Y pos: " << mySystem.get_tail()->get_data().positionY << endl;
			}
			else cout << "Nothing to print\n";
		}
		else if (choice == 4) {
			if (mySystem.numParticles()) {
				cout << "Here are the X and Y position's of all the particles currently in the particle system going from head to tail:\n";
				int counter = 0;
				for (Cell* temp = mySystem.get_head(); temp != nullptr; temp = temp->next) {
					cout << "Particle " << counter << ":\n";
					cout << "X pos: " << temp->get_data().positionX;
					cout << ", Y pos: " << temp->get_data().positionY << endl;
					counter++;
				}
			}
			else cout << "Nothing to print\n";
		}
		else if (choice == 5) cout << "The number of particles in the system is: " << mySystem.numParticles() << endl;
		else if (choice == 6) cout << "Rows: " << mySystem.get_rows() + 1 << endl << "Columns: " << mySystem.get_cols() + 1 << endl;
		/*else if (choice == 7) {
			particleGraphics g;
			mySystem.drawParticles(g);
		}*/
		//else if (choice == 8) mySystem.physics();
		else cout << "Invalid input, try again\n";
	}
	
}
