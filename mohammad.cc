#include <iostream>
#include "/public/colors.h"
#include "mohammad.h"
#include "ll.h"
#include "particle.h"
#include "particleSystem.h"
#include "particleGraphics.h"
using namespace std;

void mohammad() {
	ParticleSystem mySystem;
	int choice = -1;
	while (cin) {
		cout << "Enter a number that corresponds with one of the following options below:\n";
		cout << "0. Quit\n1. Add a particle\n2. Draw particles\n3. Move particles\n";
		cin >> choice;
		if (choice == 0) break;
		if (choice == 1) {
			int x = -1, y = -1, xv = -1, yv = -1, lifetime = -1;
			string type;
			const auto [rows, cols] = get_terminal_size();
			cout << "Enter values for the X and Y position (separately), the X and Y velocity (separately), the lifetime, and the type of the particle\n(If you do not want the particle to have a type just enter anything other than Streamer, Ballistic, or Firework)\n*Note: If you make your particle a type Streamer, but your inputs say otherwise, it will be made a Streamer\n";
			cout << "Rows: " << rows << ", Cols: " << cols << endl;
			cout << "X and Y position: ";
			cin >> x >> y;
			if (x < 0 or x > cols or y < 0 or y > rows) {
				cout << "That's out of bounds, try again!\n";
				continue;
			}
			cout << "X and Y velocity: ";
			cin >> xv >> yv;
			cout << "Lifetime: ";
			cin >> lifetime;
			cout << "Type: ";
			cin >> type;
			Particle p(x, y, xv, yv, lifetime, type);
			mySystem.addParticle(p);
			cout << "Particle added to the Particle System.\n";
		}
		if (choice == 2) {
			mySystem.drawParticles();
			movecursor(mySystem.rows, 1);
		}
		if (choice == 3) {
			mySystem.moveParticles();
			movecursor(mySystem.rows, 1);
		}
	}

}
