#pragma once

#include "cellstate.h"

#include <vector>

class GOLInterface {
public:
	// Methods
	virtual ~GOLInterface() = default;
	virtual const std::vector<std::vector<CellState>>& getGridAsVector() const = 0;
	virtual int getGridLength() = 0;
	virtual int getGridHeight() = 0;
	virtual void toggleCell(int row, int col) = 0;
	virtual void stepForward() = 0;
	virtual void clear() = 0;
};