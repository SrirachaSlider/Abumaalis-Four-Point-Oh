//This is Mohammad's section (Part C on Milestone 1)
#pragma once
#include <iostream>
#include "ll.h"
#include "particle.h"
#include "/public/colors.h"
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "particleGraphics.h"

class ParticleSystem {
	Cell *head = nullptr;
	Cell *tail = nullptr; 
	int size = 0;
public:
	int rows;
	int cols;
	ParticleSystem() {
		const auto [rowsSize,colsSize] = get_terminal_size();
		rows = rowsSize - 1;
		cols = colsSize - 1;
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
		size = 0;
	}

	//getters here but not needed bec variables are public

	int get_rows() {return rows;}

	int get_cols() {return cols;}

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
		for (Cell* current = head; current; current = current->next) {
			current->data.physics();
			current = current->next;
		}
	}
//  ---Need drawPoint done for this to work---
	void drawParticles(particleGraphics& graphics) {
		for (Cell* current = head; current; current = current->next) {
			int x = static_cast<int>(current->data.positionX);
			int y = static_cast<int>(current->data.positionY);

			if (x >= 0 and x < cols and y >= 0 and y < rows)
				graphics.drawPoint(y, x);
			current = current->next;
		}
	}

	void drawShape() {
		//stub for now, this is for drawing shapes like rectangle of a window
		return;
	}
	

};
