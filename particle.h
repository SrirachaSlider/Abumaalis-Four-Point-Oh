//this is Raj's section (Part B on Milestone 1)
#include <string>

class Particle {
public:
int positionX, positionY;
int velocityX, velocityY;
int lifetime;
std::string MovementType; // STREAMER , BALLISTIC, FIREWORK

particle(int x, int y, int vx, int vy, int life, std::string type)
: positionX(x),positionY(y), velocityX(vx), VelocityY(vy), lifetime(life), movementType(type){}

void physics(){
  // use physics logic on movement 
}
void draw(){
}
};
