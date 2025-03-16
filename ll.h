//this is Michael's section (Part A on Milestone 1)
#pragma once
#include "particle.h"

//class Particle; //Added to prevent errors. Will this be part B?

struct Cell {
	Particle* newParticle;
	Cell* next;
	Cell* prev;

	Cell(Particle* p = nullptr, Cell* newNext = nullptr, Cell* newPrev = nullptr)
		: newParticle(p), next(newNext), prev(newPrev) { }
};
