//This is Mohammad's section (Part C on Milestone 1)
#pragma once
#include <iostream>
#include "ll.h"
#include "particle.h"

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
		head = nullptr;
		tail = nullptr;
	}

	int sizeColumns = 0; //havent learned how to actually get size yet, will fix later
	int sizeRows = 0; //havent learned how to actually get size yet, will fix later
	int numParticles() {return size;}

	void addParticle(Particle p) {
		Cell* temp = new Cell(p);
		if (size == 0) {
			head = tail = temp;
		}
		else {
			temp->next = head;
			if (head) head->prev = temp;
			head = temp;
		}
		size++;
	}

	Cell *get_head() const {
		return head;
	}

	Cell *get_tail() const {
		return tail;
	}

	void moveParticles() {
		//stub for now
		return;
	}

	void drawParticles() {
		//stub for now
		return;
	}

	void drawShape() {
		//stub for now, this is for drawing shapes like rectangle of a window
		return;
	}

};
