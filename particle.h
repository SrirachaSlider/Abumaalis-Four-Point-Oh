//this is Raj's section (Part B on Milestone 1)
#include <cstring>
#include <iostream>

class Particle {
public:
double positionX, positionY;
double velocityX, velocityY;
double lifetime;
char MovementType[20]; // STREAMER , BALLISTIC, FIREWORK

Particle(double x = 0, double y = 0,double vx = 0,double vy = 0,double life = 0, const char* type = "initial")
: positionX(x),positionY(y), velocityX(vx), velocityY(vy), lifetime(life) {
setMovementType(type);
}

//function to set particle
void setParticle( double x, double y, double vx, double vy, double life, const std:: string& type) {
    positionX = x;
    positionY = y;
    positionX = vx;
    positionY = vy;
    lifetime = life;
    setMovementType(type.c_str());
}
// To set movement type

void setMovementType(const char* type){
    strncpy(MovementType, type, sizeof(MovementType) -1);
    MovementType[sizeof(MovementType) -1] ='\0';
}

void physics(){
  // use physics logic on movement
    positionX += velocityX;
    positionY += velocityY;

    if(strcmp(MovementType, "BALLISTIC") ==0) {
        velocityY += 1.0;
    }else if(strcmp(MovementType,"FIREWORK") ==0){
        if (lifetime <=0){
            std::cout << "Particle exploded into streamers\n";
        }
}

lifetime -=1; // Decrease lifetime
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
