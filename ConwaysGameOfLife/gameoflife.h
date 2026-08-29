#pragma once

#include "cellstate.h"
#include "GOLInterface.h"

#include <vector>

class GameOfLife: public GOLInterface {
public:
	// Methods
	GameOfLife(int gridLength, int gridHeight);
	CellState getCellState(int row, int col);
	void setCellState(int row, int col, CellState state);
	void toggleCell(int row, int col) override;
	void stepForward() override;
	void clear() override;
	const std::vector<std::vector<CellState>>& getGridAsVector() const;

private:
	// Members
	int gridLength;
	int gridHeight;
	std::vector<std::vector<CellState>> grid;
	std::vector<std::vector<CellState>> gridCopy;
};
