#pragma once

#include "cellstate.h"

class GOLInterface {
public:
	// Methods
	virtual ~GOLInterface() = default;
	virtual int getGridLength() = 0;
	virtual int getGridHeight() = 0;
	virtual CellState getCellState(int row, int col) = 0;
	virtual void setCellState(int row, int col, CellState state) = 0;
	virtual void toggleCellState(int row, int col) = 0;
	virtual void stepForward() = 0;
	virtual void clear() = 0;

	virtual CellState dead() = 0;
	virtual CellState alive() = 0;
};