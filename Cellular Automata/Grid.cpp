#pragma once
#include <iostream>
#include "Cell.cpp"
#include "Queue.cpp"

struct Grid {
	Cell Cells[60][60];
	Grid() {
		for (int i = 0; i <= 59; i++) {
			for (int j = 0; j <= 59; j++) {
				//Cells[i][j] = Cell();
				Cells[i][j].x = i;
				Cells[i][j].y = j;
			}
		}
	}

	int testMoore(int x, int y, bool skipHandle) {
		int living = 0;
		bool skip = false;

		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				//make sure neighbor is on grid, skip if not
				if (x + i < 0 || x + i > 59) {
					skip = true;
				}
				if (y + j < 0 || y + j > 59) {
					skip = true;
				}
				//test neighbor
				if (skip == false) {
					if (Cells[x + i][j + y].state == 1) {
						living++;
						if (i == 0 && j == 0) {
							living--;
						}
					}
				}
				//skip non-existing neighbors
				if (skip == true && skipHandle == true) {
					living++;
				}
				skip = false;
			}
		}
		return living;
	}
	
	bool floodFill(int x, int y, int target, int replace) {
		static int thing = 0;
		if (Cells[x][y].state != target) {
			return false;
		}
		Queue<Cell> Q = Queue<Cell>();
		bool queued[60][60];
		for (int i = 0; i <= 59; i++) {
			for (int j = 0; j <= 59; j++) {
				queued[i][j] = false;
			}
		}
		Q.Add(Cells[x][y]);
		while (Q.getSize() >= 1) {
			Cell t = Q.getFront();
			Q.Pop();
			Cells[t.x][t.y].state = replace;
			queued[t.x][t.y] = true;
			if (t.x - 1 >= 0) {
				if (Cells[t.x - 1][t.y].state == target && queued[t.x - 1][t.y] == false) {
					Q.Add(Cells[t.x - 1][t.y]);
					queued[t.x - 1][t.y] = true;
				}
			}
			if (t.x + 1 <= 59) {
				if (Cells[t.x + 1][t.y].state == target && queued[t.x + 1][t.y] == false) {
					Q.Add(Cells[t.x + 1][t.y]);
					queued[t.x + 1][t.y] = true;
				}
			}
			if (t.y - 1 >= 0) {
				if (Cells[t.x][t.y - 1].state == target && queued[t.x][t.y - 1] == false) {	
					Q.Add(Cells[t.x][t.y - 1]);
					queued[t.x][t.y - 1] = true;
				}
			}
			if (t.y + 1 <= 59) {
				if (Cells[t.x][t.y + 1].state == target && queued[t.x][t.y + 1] == false) {			
					Q.Add(Cells[t.x][t.y + 1]);
					queued[t.x][t.y + 1] = true;
				}
			}
		}
		return true;
	}
	
	friend std::ostream &operator <<(std::ostream &output, const Grid &grid) {
		for (int i = 0; i <= 59; i++) {
			for (int j = 0; j <= 59; j++) {
				if (grid.Cells[i][j].state >= 1) {
					output << grid.Cells[i][j].state-1;
				}
				else {
					output << " ";
				}
			}
			output << std::endl;
		}
		return output;
	}

	void operator = (Grid &other) {
		for (int i = 0; i <= 59; i++) {
			for (int j = 0; j <= 59; j++) {
				Cells[i][j].state = other.Cells[i][j].state;
			}
		}
	}
};