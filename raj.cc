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
		cout << "0 to quit\n1 to add particle\n2 to move particle\n";
		cin >> choice;
		if (choice ==0) break;
		if(choice == 1){
			Particle x(rand() % 50, rand () % 20, rand() % 5-2, rand() % 5-2, 50);
			mySystem.addParticle(x);
		}
		if (choice == 2) {
			mySystem.moveParticles();
			clearscreen();
			movecursor(1,1);
		}
	}


	//create random particles
	/*for (int i = 0; i < 100; i++){ // run 100 frames
	  clearscreen();
	  mySystem.moveParticles();

	//change color when bounce
	Particle* current = mySystem.get_head():
	while (current != nullptr){
	if (current->hasBounced()){
	setcolor(rand() % 256,rand() % 256,rand() % 256,);
	}
	current = current->next;
	}

	mySystem.drawParticles();
	usleep(100000);
	}
	}
	movecursor(1 , 1);
	resetcolor();*/
mySystem.drawParticles();
mySystem.moveParticles();
clearscreen();
movecursor(1,1);
}


