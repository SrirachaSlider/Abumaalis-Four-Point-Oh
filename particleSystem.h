//This is Mohammad's section (Part C on Milestone 1)
#pragma once
#include <iostream>
#include "ll.h"
#include "particle.h"
#include "/public/colors.h"
#include <cstdlib>
#include <ctime>
#include <cassert>

class ParticleSystem {
	Cell *head = nullptr;
	Cell *tail = nullptr; 
	int size = 0;
	int rowsSize;
	int colsSize;
	public:
	ParticleSystem() {
		const auto [rows,cols] = get_terminal_size();
		rowsSize = rows;
		colsSize = cols;
	}
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

	int get_rows() {return rowsSize;}

	int get_cols() {return colsSize;}

	/*auto termSize = get_terminal_size();
	int rows = size[0];
	int cols = size[1];*/
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
