//this is Raj's section (Part B on Milestone 1)
#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
//class ParticleSystem;
//extern ParticleSystem p;  // Global instance

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
			if (MovementType == "STREAMER") {
				if (std::abs(velocityX) > std::abs(velocityY)) {
					velocityY = 0;  // Move only horizontally
				} else {
					velocityX = 0;  // Move only vertically
				}
			}
			lifetime -=1;
		}

		void explode(){

			// New particles have half the lifetime of the original
			int newLifetime = lifetime / 2;
			if (newLifetime <= 0) newLifetime = 1;  // Ensure particles last at least 1 frame

			// Define 4 break-off directions (right, left, up, down)
			double speed = 3.0; // Moderate speed
			double directions[4][2] = {
				{speed, 0},  // Right
				{-speed, 0}, // Left
				{0, -speed}, // Up
				{0, speed}   // Down
			};

			// Create and add 4 new particles to the linked list
			/*for (int i = 0; i < 4; ++i) {
				p.addParticle(Particle(positionX, positionY, directions[i][0], directions[i][1], newLifetime, "FRAGMENT"));
			}*/
		}
		/*	void draw() const {
			std::cout << "Drawing particle at ( " << positionX << "," << positionY << ") of type " << MovementType << "\n";
			}*/

		void printDetails() const{
			std::cout << "Particle Details:\n";
			std::cout << "Position: (" << positionX << ", " << positionY << ")\n";
			std::cout << "velocity: (" << velocityX << ", " << velocityY << ")\n";
			std::cout << "LifetieL " << lifetime << "\n";
			std::cout << "Movement Type:" << MovementType << "\n";
		}
};

