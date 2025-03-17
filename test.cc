//code being tested here
#include <iostream>
#include "ll.h"
#include "particle.h"
#include "particleSystem.h"
using namespace std;

void test() {
	ParticleSystem mySystem;
	Particle p(1, 1, 1, 1, 1, "test");
	mySystem.addParticle(p);
	cout << mySystem.numParticles() << endl;
}
