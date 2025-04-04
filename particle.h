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
		int x, y, rows = 0, cols = 0; // for positions
		double dx, dy; // for velocities
		int lifetime;
		string type;
		bool make_firework = false;
		//static int screen_width, screen_height; // Store screen size

		//string MovementType; // STREAMER , BALLISTIC, FIREWORK
		// Constructor
		Particle(int start_x = 0, int start_y = 0, double vx = 0, double vy = 0, int life = 0, string myType = "none")
			:x(start_x), y(start_y), dx(vx), dy(vy), lifetime(life), type(myType) {
				const auto [myRows, myCols] = get_terminal_size();
				rows = myRows - 1;
				cols = myCols - 1;
				if (type == "streamer" or type == "STREAMER" or type == "Streamer") {
					if (dx >= dy) dy = 0;
					else dx = 0;
				}
				if (type == "firework" or type == "FIREWORK" or type == "Firework") make_firework = true;
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

			if (type == "streamer" or type == "STREAMER" or type == "Streamer") {
			  if (dx >= dy) dy = 0;
			  else dx = 0;
			}
			if (type == "ballistic" or type == "BALLISTIC" or type == "Ballistic") dy += 1;
			//if (type == "firework" or type == "FIREWORK" or type == "Firework") make_firework = true;

			// Basic physics logic
			x += dx;
			y += dy;

			//Bounce off edges of screen ballistic
			if (x < 0){
				x = 0;
				dx *= -1;
			}
			if (x >= cols){
				x = cols - (x-cols);
				dx *= -1;
			}
			if (y < 0){
				y = 0;
				dy *= -1;
			}
			if (y >= rows){
				y = rows - (y - rows);
				dy *= -1;
			}
			// firework gravity
			//if (apply_gravity) dy += 1.0;

			//decrement lifetime

			lifetime--;
		}

		bool is_alive() const {
			return lifetime > 0;
		}

		Particle explode(int i) const{
			double angle = i * M_PI/ 180.0; // convert degree to radian
			double vx = cos(angle) * 2.0; //explode speed
			double vy = sin(angle) * 2.0; 
			int new_x = std::max(0, std::min(x, cols - 1));
			int new_y = std::max(0, std::min(y, rows - 1));
			return Particle(x, y, vx, vy, 30, "streamer");
		}
};
