//this is Raj's section (Part B on Milestone 1)
#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;


class Particle {
	public:
		double positionX, positionY;
		double velocityX, velocityY;
		double lifetime;
		string MovementType; // STREAMER , BALLISTIC, FIREWORK
		// Constructor
		Particle(double x = 0, double y = 0,double vx = 0,double vy = 0,double life = 0, string type  = "empty")
			: positionX(x),positionY(y), velocityX(vx), velocityY(vy), lifetime(life), MovementType(type){
			}
		// To set movement type

		/*void setMovementType(const char* type){
			strncpy(MovementType, type, sizeof(MovementType) -1);
			MovementType[sizeof(MovementType) -1] ='\0';
		}*/

		void physics() {
    // Basic physics logic
    positionX += velocityX;
    positionY += velocityY;

    if (MovementType == "BALLISTIC") {
        velocityY += 1.0;
    } else if (MovementType == "FIREWORK") {
        if (lifetime <= 0) {
			explode();
		}
	}
	else if (MovementType == "STREAMER"){
	}
	lifetime -=1;
		}

		void explode(){
			cout << "Firework exploded into 8 streamers!\n";
			const int numParticles = 8;
			for (int i = 0; i< numParticles; ++i){
				double angle = i * 45.0 * (3.14159265 / 180.0);
				double speed = 5.0;
				double vx = cos(angle) * speed;
				double vy = sin(angle) * speed;
				Particle streamer(positionX, positionY,vx, vy, 30, "STREAMER");
				streamer.draw();
			}
		}

		void draw() const {
			std::cout << "Drawing particle at ( " << positionX << "," << positionY << ") of type " << MovementType << "\n";
		}

		void printDetails() const{
			std::cout << "Particle Details:\n";
			std::cout << "Position: (" << positionX << ", " << positionY << ")\n";
			std::cout << "velocity: (" << velocityX << ", " << velocityY << ")\n";
			std::cout << "LifetieL " << lifetime << "\n";
			std::cout << "Movement Type:" << MovementType << "\n";
		}
};

