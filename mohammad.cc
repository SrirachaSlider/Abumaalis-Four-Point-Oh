#include <iostream>
#include "/public/colors.h"
#include "mohammad.h"
#include "ll.h"
#include "particle.h"
#include "particleSystem.h"
#include "particleGraphics.h"
using namespace std;

void mohammad() {
	/*cout << "This is Mohammad's portion\n";
	int x = 0;
	cout << "Enter a number to square:\n";
	cin >> x;
	cout << x << " squared is: " << x * x << endl;*/
	ParticleSystem mySystem;
	Particle p(5, 5, 1, 1, 50);
	Particle c(30, 30, 2, 2, 50);
	Particle d(10, 1, 3, 3, 50);
	mySystem.addParticle(p);
	mySystem.addParticle(c);
	mySystem.addParticle(d);
	mySystem.drawParticles();
	mySystem.moveParticles();
	//usleep(1000000);
	resetcolor();
	clearscreen();
}
