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
		cout << "0. Type '0' to quit\n1. Add a particle to the Particle System (will be added to the head of the linked list)\n2. Print number that you associated the particle at head with\n3. Print number that you associated the particle at tail with\n4. Print the numbers associated with all the particles in the Particle System (linked list print)\n5. Print size of linked list / number of particles\n6. Test moveParticles(), drawParticles(), and drawShape()\n";
		cin >> choice;
		if (choice == 0) break;
		else if (choice == 1) {
			cout << "Insert a number to associate with the particle you are adding (will be added to head of linked list)\n";
			double ins;
			cin >> ins;
			Particle p(ins);
			mySystem.addParticle(p);
			cout << "Particle added" << endl;
		}
		else if (choice == 2) {
			if (mySystem.get_head() != nullptr) cout << "The number that you associated the particle with is: " << mySystem.get_head()->get_data().positionX << endl;
			else cout << "Nothing to print\n";
		}
		else if (choice == 3) {
			if (mySystem.get_tail() != nullptr) cout << "The number that you associated the particle with is: " << mySystem.get_tail()->get_data().positionX << endl;
            else cout << "Nothing to print\n";
		}
		else if (choice == 4) {
			if (mySystem.numParticles()) {
				cout << "Here are the numbers of all the particles associated with each particle going from head to tail:\n";
				for (Cell* temp = mySystem.get_head(); temp != nullptr; temp = temp->next) {
					cout << temp->get_data().positionX << " ";
				}
				cout << endl;
			}
			else cout << "Nothing to print\n";
		}
		else if (choice == 5) cout << "The number of particles in the system is: " << mySystem.numParticles() << endl;
		else if (choice == 6) {
			cout << "This just calls moveParticles(), drawParticles(), and drawShape(), they are all currently stub functions, but this shows that they are able to be called\n";
			//mySystem.moveParticles();
			//mySystem.drawParticles();
			//mySystem.drawShape();
		}
		else if (choice == 7) cout << mySystem.get_rows() << mySystem.get_cols();
		else cout << "Invalid input, try again\n";
	}
	
}
