//this is Michael's section (Part A on Milestone 1)
#pragma once
#include "particle.h"

struct Cell {
	Particle* newParticle;
	Cell* next;
	Cell* prev;

	Cell(Particle* p = nullptr, Cell* newNext = nullptr, Cell* newPrev = nullptr)
		: newParticle(p), next(newNext), prev(newPrev) { }
};
