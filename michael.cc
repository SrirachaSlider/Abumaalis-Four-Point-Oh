#include <iostream>
#include "michael.h"
#include "ll.h"
#include "particle.h"
#include "particleSystem.h"
#include "particleGraphics.h"
using namespace std;

void michael() {
	//cout << "This is Michael's portion\n";
	ParticleSystem swag;

	for (int i = 0; i < 5; i++) {
		int x = rand() % swag.get_cols();
		int y = rand() % swag.get_rows();
		swag.addParticle(Particle(x, y, 0, -3, 50, "firework"));
	}

	for (int i = 0; i < 100; i++) {
		swag.moveParticles();
		usleep(100'000);
	}
}
