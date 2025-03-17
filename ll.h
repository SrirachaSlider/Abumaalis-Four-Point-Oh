//this is Michael's section (Part A on Milestone 1)
#pragma once
#include "particle.h"

struct Cell {
	//changed this to data for better accuracy
	Particle data;
	Cell* next;
	Cell* prev;

	Cell(Particle p, Cell* newNext = nullptr, Cell* newPrev = nullptr)
		: data(p), next(newNext), prev(newPrev) { }

	//adding this purely for test.cc so i can show that the linked list of particles is working
	Particle& get_data() {return data;}
};
