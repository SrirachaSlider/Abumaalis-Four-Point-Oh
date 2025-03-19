//this is Raj's section (Part B on Milestone 1)
#pragma once
#include <string>

class Particle {
public:
double positionX, positionY;
double velocityX, velocityY;
double lifetime;
std::string movementType; // STREAMER , BALLISTIC, FIREWORK

Particle(double x = 0, double y = 0, double vx = 0, double vy = 0, double life = 0, std::string type = "initial")
: positionX(x),positionY(y), velocityX(vx), velocityY(vy), lifetime(life), movementType(type){}

void physics(){
  // use physics logic on movement 
}
void draw(){
}
};
//test
