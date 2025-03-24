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
	int rows = 0;
	int cols = 0;
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
			temp->prev = tail;
			if (tail) tail->next = temp;
			tail = temp;
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
			
			if (current->data.lifetime <= 0) {
				
				Cell* temp = current;

				if (temp->prev)
					temp->prev->next = temp->next;
				if (temp->next)
					temp->next->prev = temp->prev;
				if (temp == head)
					head = temp->next;
				if (temp == tail)
					tail = temp->prev;

				delete temp;
				size--;
			} else {
				current = current->next;
			}
		}
	}

	void drawParticles() {
		particleGraphics graphics;
		for (Cell* current = head; current; current = current->next) {
			double x = current->data.positionX;
			double y = current->data.positionY;

			if (x >= 0 and x < cols and y >= 0 and y < rows)
				graphics.drawPoint(y, x);
		}
	}

	void drawShape() { // Need to add invalid input checks
		particleGraphics g;
		int choice;
		while (true) {
			cout << "Enter a number to draw a shape:\n";
			cout << "1. Rectangle\n2. Vertical line\n3. Horizontal line\n";
			cin >> choice;

			if (choice < 1 or choice > 3) {
				cout << "Invalid choice. Please enter 1, 2, or 3\n";
				continue;
			} else if (choice == 1) {
				int x_one, x_two, y_one, y_two;
				cout << "Enter coordinates for the square in this order: x1 y1 x2 y2:\n";
				cin >> x_one >> y_one >> x_two >> y_two;
				g.drawRectangle(x_one, x_two, y_one, y_two);
			} else if (choice == 2) {
				int y_one, y_two, x;
				cout << "Enter coordinates for the vertical line in this order: y1 y2 x:\n";
				cin >> y_one >> y_two >> x;
				g.drawVertLine(y_one, y_two, x);
			} else if (choice == 3) {
				int x_one, x_two, y;
				cout << "Enter coordinates for the horizontal line in this order: x1 x2 y:\n";
				cin >> x_one >> x_two >> y;
				g.drawHorizLine(x_one, x_two, y);
			}
			break;
		}
	}
	

};
