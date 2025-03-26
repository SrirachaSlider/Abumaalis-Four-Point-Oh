#include <iostream>
#include "raj.h"
#include "ll.h"
#include "particle.h"
#include "particleSystem.h"
#include "particleGraphics.h"
#include "/public/colors.h"
#include <unistd.h>
#include <string>
using namespace std;

void raj() {
	cout << "This is Raj's portion\n";

	srand(time(0));
	ParticleSystem mySystem;
	int choice = 1;
	while (cin) {
	cout << "0 to quit\n1 to add random particle\n2 to move particles\n3 add your own particle\n4 print ERROR screen\n";
		cin >> choice;
		
		if(choice ==0) break;
		if(choice == 1){
			Particle x(rand() % 50, rand () % 20, rand() % 5-2, rand() % 5-2, 50);
			mySystem.addParticle(x);
			cout <<"Particle added! keep pressing '1' and Enter to add more Particles.\n";
		}
		
		else if (choice == 2) {
			mySystem.drawParticles();
			mySystem.moveParticles();
			clearscreen();
			movecursor(1,1);
		}
		/*else if(choice == 3){
			cout << "Removing the first particle...\n";
            mySystem.removeParticles(0);
		}*/
		else if (choice == 3){

			int x, y, dx, dy, lifetime;
			string type;
			cout <<"Enter x, y, dx, dy lifetime and type:\n";
			cin>>x>>y >> dx >> dy>>lifetime;
			cin >>type;
			Particle p(x, y, dx, dy, lifetime, type);
			mySystem.addParticle(p);
		}
		/*else if (choice == 5){
			int lifetime;
			cout << "Enter new lifetime: ";
			cin >> lifetime;
			mySystem.setParticleLifetime(0, ifetime);
		}
		else if(choice == 6){
			mySystem.clearParticles();
			cout << "All particles cleared!\n";
		}*/
		else if (choice == 4){ // error screen
			clearscreen();
		for (int i = 0; i < 20; i++){ // 20 rows
			for (int j = 0; j < 50; j++) { //50 columns
				cout <<"ERROR ";
			}
			cout <<endl;
		}
		usleep(10000000);
		clearscreen();
	}
	//mySystem.drawParticles();
	//mySystem.moveParticles();
	//clearscreen();
	//movecursor(1,1);
	}
}




