#pragma once

#include "cellstate.h"
#include "golinterface.h"

#include <vector>

class GameOfLife: public GOLInterface {
public:
	// Methods
	GameOfLife(int gridLength, int gridHeight);
	
	int getGridLength() override;
	int getGridHeight() override;
	CellState getCellState(int row, int col) override;
	void setCellState(int row, int col, CellState state) override;
	void toggleCellState(int row, int col) override;
	void stepForward() override;
	void clear() override;
	void saveGridState() override;
	void loadGridState() override;
	bool getIsModified() override;

	CellState dead() override;
	CellState alive() override;

private:
	// Members
	int gridLength;
	int gridHeight;
	std::vector<std::vector<CellState>> grid;
	std::vector<std::vector<CellState>> gridCopy;
	std::vector<std::vector<CellState>> gridSaveState;
	bool isModified;

	void setCellState_(int row, int col, CellState state);
	void toggleCellState_(int row, int col);

	// Methods
	CellState getGridCopyCellState(int row, int col);
};
