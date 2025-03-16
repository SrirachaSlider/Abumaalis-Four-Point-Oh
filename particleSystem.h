//This is Mohammad's section (Part C on Milestone 1)
#pragma once
#include <iostream>
#include "ll.h"
#include "particle.h"
using namespace std;

class ParticleSystem {
	Cell *head = nullptr;
	Cell *tail = nullptr; 
	int size = 0;
	public:
	//not sure if supposed to be constructor and or deconstructor, but its here for now, will remove later if necessary
	ParticleSystem() {}
	~ParticleSystem() {
		Cell* temp = head;
		while (temp) {
			Cell* copy = temp;
			temp = temp->next;
			delete copy;
		}
	}

	int sizeColumns = 0; //havent learned how to actually get size yet, will fix later
	int sizeRows = 0; //havent learned how to actually get size yet, will fix later
	int numParticles() {return size;}

	void addParticle() {
		Cell* temp = new Cell;
		temp->next = head;
		if (head) head->prev = temp;
		head = temp;
		size++;
	}

	auto moveParticles() {
		//dont know return type yet
		//stub for now
		return;
	}

	auto drawParticles() {
		//dont know return type yet
		//stub for now
		return;
	}

};
