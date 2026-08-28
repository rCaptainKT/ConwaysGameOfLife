#pragma once

#include <vector>

enum class CellState {
	DEAD,
	ALIVE
};

class GameOfLife {
public:
	// Methods
	GameOfLife(int gridLength, int gridHeight);
	CellState getCellState(int row, int col);
	void setCellState(int row, int col, CellState state);
	void toggleCell(int row, int col);
	void stepForward();
	void clear();

private:
	// Members
	int gridLength;
	int gridHeight;
	std::vector<std::vector<CellState>> grid;
	std::vector<std::vector<CellState>> gridCopy;
};
