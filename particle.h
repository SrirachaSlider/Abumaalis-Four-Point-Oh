//this is Raj's section (Part B on Milestone 1)
#include <iostream>

class MovementType { STREAMER, BALLISTIC, FIREWORK};

class Particle {
public:
int x,y ;
int VelocityX, velocityY;
int lifetime;
MovementType type;
};
