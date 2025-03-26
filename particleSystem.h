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
		//for (Cell* current = head;; current = current->next) {
		while (size > 0) {
			//clearscreen();
			Cell* current = head;
			while (current) {
				current->data.physics();

				if (current->data.lifetime <= 0) {

					Cell* temp = current;
					current = current->next;

					//if (temp->data.make_firework)
					//	createFirework(temp->data);

					Particle fireParticle = temp->data;

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

					if (fireParticle.make_firework) createFirework(fireParticle);
				} 
				else {
					current = current->next;
				}
				if (size == 0) break;
			}

			drawParticles();
			usleep(100000);

		}
		show_cursor(true);
	}

	void drawParticles() {
		particleGraphics graphics;
		show_cursor(false);
		clearscreen();
		for (Cell* current = head; current; current = current->next) {
			double x = current->data.x;
			double y = current->data.y;

			if (x >= 0 and x < cols and y >= 0 and y < rows) {
				graphics.drawPoint(y, x);
				//resetcolor();
			}
		}
	}

	void drawShape() { // Need to add invalid input checks
		particleGraphics g;
		int choice;
		while (true) {
			cout << "Enter a number to draw a shape:\n";
			cout << "0. Quit\n1. Rectangle\n2. Line\n";
			cin >> choice;

			if (choice < 0 or choice > 2) {
				cout << "Invalid choice. Please enter 0, 1, or 2\n";
				continue;
			}
			else if (choice == 0) break;
			else if (choice == 1) {
				int x_one, x_two, y_one, y_two;
				cout << "Enter coordinates for the square in this order: x1, x2, y1, y2:\n";
				cout << "Max X: " << ((cols+1)/2) << ", Max Y: " << rows << endl;
				cin >> x_one >> x_two >> y_one >> y_two;
				if (x_one > ((cols+1)/2) or x_two > ((cols+1)/2) or x_one < 0 or x_two < 0 or y_one > rows or y_two > rows or y_one < 0 or y_two < 0) {
					cout << "Out of bounds, try again!\n";
					continue;
				}
				g.drawRectangle(x_one, x_two, y_one, y_two);
			} 
			/*else if (choice == 2) {
			  int y_one, y_two, x;
			  cout << "Enter coordinates for the vertical line in this order: y1 y2 x:\n";
			  cin >> y_one >> y_two >> x;
			  g.drawVertLine(y_one, y_two, x);
			  } 
			  else if (choice == 3) {
			  int x_one, x_two, y;
			  cout << "Enter coordinates for the horizontal line in this order: x1 x2 y:\n";
			  cin >> x_one >> x_two >> y;
			  g.drawHorizLine(x_one, x_two, y);
			  }*/
			else if (choice == 2) {
				cout << "Enter coordinates in this order: x1, x2, y1, y2\n";
				int x1, x2, y1, y2;
				cin >> x1 >> x2 >> y1 >> y2;
				g.drawLine(x1, x2, y1, y2);

			}
		}
	}

	void createFirework(Particle& p) {
		for (int i = 0; i < 360; i += 90) {
			addParticle(p.explode(i));
		}
	}

	};
