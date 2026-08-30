#include "gameoflife.h"
#include "cellstate.h"

#include <vector>

GameOfLife::GameOfLife(int gridLength, int gridHeight) {
	this->gridLength = gridLength;
	this->gridHeight = gridHeight;
	this->grid = std::vector<std::vector<CellState>>(gridHeight, std::vector<CellState>(gridLength, CellState::DEAD));
}

int GameOfLife::getGridLength() {
	return this->gridLength;
}

int GameOfLife::getGridHeight() {
	return this->gridHeight;
}

CellState GameOfLife::getCellState(int row, int col) {
	return this->grid.at(row).at(col);
}

void GameOfLife::setCellState(int row, int col, CellState state) {
	this->grid.at(row).at(col) = state;
}

void GameOfLife::toggleCellState(int row, int col) {
	if (this->getCellState(row, col) == CellState::DEAD) {
		this->setCellState(row, col, CellState::ALIVE);
	} else if (this->getCellState(row, col) == CellState::ALIVE) {
		this->setCellState(row, col, CellState::DEAD);
	}
}

void GameOfLife::stepForward() {
	this->gridCopy = this->grid;

	for (int i = 0; i < this->gridHeight; i++) {
		for (int j = 0; j < this->gridLength; j++) {
			int neighbours = 0;
			for (int k = i - 1; k < i + 2; k++) {
				if (k < 0 || k > this->gridHeight-1) {
					continue;
				}
				for (int l = j - 1; j < j + 2; l++) {
					if (l < 0 || l > this->gridLength - 1) {
						continue;
					} else if (i == k && j == l) {
						continue;
					} else if (this->getCellState(k, l) == CellState::ALIVE) {
						neighbours++;
					}
				}
			}
			
			if (this->getCellState(i, j) == CellState::ALIVE) {
				if (neighbours < 2) {
					// Underpopulation
					this->setCellState(i, j, CellState::DEAD);
				} else if (neighbours > 3) {
					// Overpopulation
					this->setCellState(i, j, CellState::DEAD);
				}
			} else {
				if (neighbours == 3) {
					// Reproduction
					this->setCellState(i, j, CellState::ALIVE);
				}
			}
		}
	}
}

void GameOfLife::clear() {
	for (int i = 0; i < this->gridHeight; i++) {
		for (int j = 0; j < this->gridLength; j++) {
			this->grid.at(i).at(j) = CellState::DEAD;
		}
	}
}

CellState GameOfLife::dead() {
	return CellState::DEAD;
}

CellState GameOfLife::alive() {
	return CellState::ALIVE;
}