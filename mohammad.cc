#include <iostream>
#include "/public/colors.h"
#include "mohammad.h"
#include "ll.h"
#include "particle.h"
#include "particleSystem.h"
#include "particleGraphics.h"
#include <ctime>
using namespace std;

void mohammad() {
	ParticleSystem mySystem;
	srand(time(0));
	int choice = -1;
	bool drawParticles = false;
	while (cin) {
		cout << "Enter a number that corresponds with one of the following options below:\n";
		cout << "0. Quit\n1. Add a particle\n2. Add a drawing\n3. Draw particles\n4. Move particles\n";
		cin >> choice;
		if (choice == 0) break;
		else if (choice == 1) {
			int x = -1, y = -1, xv = -1, yv = -1, lifetime = -1;
			string type;
			const auto [rows, cols] = get_terminal_size();
			cout << "Enter values for the X and Y position (separately), the X and Y velocity (separately), the lifetime, and the type of the particle (Enter 0 for all for random values)\n(If you do not want the particle to have a type just enter anything other than Streamer, Ballistic, or Firework)\n*Note: If you make your particle a type Streamer, but your inputs say otherwise, it will be made a Streamer\n";
			cout << "Max X: " << cols << ", Max Y: " << rows << endl;
			cout << "X and Y position: ";
			cin >> x >> y;
			if (x < 0 or x > cols or y < 0 or y > rows) {
				cout << "That's out of bounds, try again!\n";
				continue;
			}
			cout << "X and Y velocity: ";
			cin >> xv >> yv;
			if (xv > 100 or yv > 100) {
				cout << "Chill out\n";
				continue;
			}
			cout << "Lifetime: ";
			cin >> lifetime;
			if (lifetime > 1000) {
				cout << "That will take too long\n";
				continue;
			}
			cout << "Type: ";
			cin >> type;
			Particle p;
			if (x == 0 and y == 0 and xv == 0 and yv == 0 and lifetime == 0) {
				p = Particle(rand() % mySystem.cols, rand() % mySystem.rows, rand() % 10, rand() % 10, rand() % 100);
			}
			else {
				p = Particle(x, y, xv, yv, lifetime, type);
			}
			mySystem.addParticle(p);
			cout << "Particle added to the Particle System.\n";
		}
		else if (choice == 2) {
			clearscreen();
			movecursor(1,1);
			mySystem.drawShape();
			movecursor(mySystem.rows, 1);
		}
		else if (choice == 3) {
			if (!mySystem.get_head()) {
				cout << "Error, nothing to draw, try again!\n";
				continue;
			}
			drawParticles = true;
			mySystem.drawParticles();
			movecursor(mySystem.rows, 1);
		}
		else if (choice == 4) {
			if (!drawParticles) {
				cout << "Error, must draw particles first, try again!\n";
				continue;
			}
			else drawParticles = false;
			mySystem.moveParticles();
			resetcolor();
			clearscreen();
			movecursor(1, 1);
		}
		else cout << "Invalid Input, Try Again.\n";
	}

}
