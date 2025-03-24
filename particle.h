//this is Raj's section (Part B on Milestone 1)
#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include "/public/colors.h"
using namespace std;
//class ParticleSystem;
//extern ParticleSystem p;  // Global instance

class Particle {
	public:
		int x, y; // for positions
		double dx, dy; // for velocities
		int lifetime;
		bool apply_gravity;
		bool make_firework = false;
		static int screen_width, screen_height; // Store screen size

		//string MovementType; // STREAMER , BALLISTIC, FIREWORK
							 // Constructor
		Particle(int start_x, int start_y, double vx, double vy, int life, bool gravity = true)
			:x(start_x), y(start_y), dx(vx), dy(vy), lifetime(life), apply_gravity(gravity) {
				auto [rows, cols] = get_terminal_size();
				rows--;
				cols--;
			}
		// To set movement type

		/*void setMovementType(const char* type){
		  strncpy(MovementType, type, sizeof(MovementType) -1);
		  MovementType[sizeof(MovementType) -1] ='\0';
		  }*/
		/*static void setScreenSize(int width, int height){
			screen_width = width;
			screen_height = height;
		}*/

		void physics(){

			// Basic physics logic
			x += dx;
			y += dy;

			//Bounce off edges of screen ballistic
			if (x < 0){
				x = 0;
				dx = -dx;
			}
			if (x >= screen_width){
				x = screen_width -1;
				dx = -dx;
			}
			if (y < 0){
				y = 0;
				dy = -dy;
			}
			if (y >= screen_height){
				y = screen_height -1;
				dy = -dy;
			}
			// firework gravity
			if (apply_gravity) dy += 1.0;

			//decrement lifetime
			lifetime--;
		}
	
		bool is_alive() const {
			return lifetime > 0;
		}

		void explode() const{
			for (int i = 0; i < 360; i+= 90){ //creating 4 particles
			double angle = i * M_PI/ 180.0; // convert degree to radian
			double vx = cos(angle) * 2.0; //explode speed
			double vy = sin(angle) * 2.0; 
			//new_particles.push_back(Particle(x,y,vx,vy,30,false)); // streamer particle

		}
}
};
