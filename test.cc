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
	cout << "This is where the different functions will be tested\nPick a number to try things out\n";
	int choice = 0;
	while (cin) {
		cout << "1. Add a particle to the Particle System(will be added to the head of the linked list)\n2. Print particle at head\n3. Print particle at tail\n4. Print the names of all the particles in the Particle System (linked list print)\n";
		cin >> choice;
		if (choice == 1) cout << "testing..\n";
	}
	
}
