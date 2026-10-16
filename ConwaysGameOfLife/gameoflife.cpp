#include "gameoflife.h"
#include "cellstate.h"

#include <vector>

GameOfLife::GameOfLife(int gridLength, int gridHeight) {
	this->gridLength = gridLength;
	this->gridHeight = gridHeight;
	this->grid = std::vector<std::vector<CellState>>(gridHeight, std::vector<CellState>(gridLength, CellState::DEAD));
	this->gridSaveState = this->grid;
	this->isModified = false;
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
	this->setCellState_(row, col, state);
	this->gridSaveState = this->grid;
	this->isModified = false;
}

void GameOfLife::setCellState_(int row, int col, CellState state) {
	this->grid.at(row).at(col) = state;
}

void GameOfLife::toggleCellState(int row, int col) {
	this->toggleCellState_(row, col);
	this->gridSaveState = this->grid;
	this->isModified = false;
}

void GameOfLife::toggleCellState_(int row, int col) {
	if (this->getCellState(row, col) == CellState::DEAD) {
		this->setCellState_(row, col, CellState::ALIVE);
	} else if (this->getCellState(row, col) == CellState::ALIVE) {
		this->setCellState_(row, col, CellState::DEAD);
	}
}

CellState GameOfLife::getGridCopyCellState(int row, int col) {
	return this->gridCopy.at(row).at(col);
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
				for (int l = j - 1; l < j + 2; l++) {
					if (l < 0 || l > this->gridLength - 1) {
						continue;
					} else if (i == k && j == l) {
						continue;
					} else if (this->getGridCopyCellState(k, l) == CellState::ALIVE) {
						neighbours++;
					}
				}
			}
			
			if (this->getCellState(i, j) == CellState::ALIVE) {
				if (neighbours < 2) {
					// Underpopulation
					this->setCellState_(i, j, CellState::DEAD);
				} else if (neighbours > 3) {
					// Overpopulation
					this->setCellState_(i, j, CellState::DEAD);
				}
			} else {
				if (neighbours == 3) {
					// Reproduction
					this->setCellState_(i, j, CellState::ALIVE);
				}
			}
		}
	}

	this->isModified = true;
}

void GameOfLife::clear() {
	for (int i = 0; i < this->gridHeight; i++) {
		for (int j = 0; j < this->gridLength; j++) {
			this->grid.at(i).at(j) = CellState::DEAD;
		}
	}
	this->gridSaveState = this->grid;
	this->isModified = false;
}

void GameOfLife::saveGridState() {
	this->gridSaveState = this->grid;
	this->isModified = false;
}

void GameOfLife::loadGridState() {
	this->grid = this->gridSaveState;
	this->isModified = false;
}

bool GameOfLife::getIsModified() {
	return this->isModified;
}

CellState GameOfLife::dead() {
	return CellState::DEAD;
}

CellState GameOfLife::alive() {
	return CellState::ALIVE;
}