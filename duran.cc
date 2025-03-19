#include <iostream>
#include "duran.h"
#include "ll.h"
#include "particle.h"
#include "particleSystem.h"
#include "particleGraphics.h"
#include "/public/colors.h"
using namespace std;

void duran() {
	particleGraphics test;
	cout << RED;
	test.drawPoint(10,10);
	resetcolor();
}
