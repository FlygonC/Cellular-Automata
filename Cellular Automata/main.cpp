#pragma once
#include <iostream>
#include <time.h>
#include "Grid.cpp"

using namespace std;

Grid nextGeneration(Grid &input, int generations) {
	Grid temp = input;
	for (int i = 0; i < generations; i++) {
		/*for (int i = 0; i <= 59; i++) {
		for (int j = 0; j <= 59; j++) {
		cout << input.testMoore(i, j, true);
		}
		cout << endl;
		}*/


		for (int i = 0; i <= 59; i++) {
			for (int j = 0; j <= 59; j++) {
				if (input.Cells[i][j].state == 0 && input.testMoore(i, j, true) > 4) {
					temp.Cells[i][j].state = 1;
				}

				if (input.Cells[i][j].state == 1 && input.testMoore(i, j, true) < 4) {
					temp.Cells[i][j].state = 0;
				}
				/*if (World.Cells[i][j].life == true && World.testMoore(i, j, false) > 6) {
				temp.Cells[i][j].life = false;
				}*/
			}
		}
		//input = temp;
	}
	return temp;
}

int main() {
	int seed = time(NULL);
	//srand(time(NULL));
	srand(seed);

	int density = 45;
	int genSkip = 1;

	int Generation = 1;
	Grid World;

	for (int i = 0; i <= 59; i++) {
		for (int j = 0; j <= 59; j++) {
			if (rand() % 100 <= density) {
				World.Cells[i][j].state = 1;
			}
			else {
				World.Cells[i][j].state = 0;
			}
		}
	}

	cout << "Generation: " << Generation << "  Seed: " << seed << endl;
	cout << World;
	system("pause");

	while (true) {
		Generation += genSkip;
		
		//cout << temp;
		World = nextGeneration(World, genSkip);

		//cout << World;
		int cavernsFound = 0;
		for (int i = 0; i <= 59; i++) {
			for (int j = 0; j <= 59; j++) {
				if (World.floodFill(i, j, 0, 3)) {			
					cavernsFound++;
				}
				//cout << World.Cells[i][j].state;
			}
			//cout << endl;
		}

		for (int i = 0; i <= 59; i++) {
			for (int j = 0; j <= 59; j++) {
				World.floodFill(i, j, 3, 0);
				//cout << World.Cells[i][j].state;
			}
			//cout << endl;
		}

		cout << "Generation: " << Generation << "" << endl;
		cout << "Caverns Found: " << cavernsFound << endl;
		cout << World;
		system("pause");
	}

	return 0;
}