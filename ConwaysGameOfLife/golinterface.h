#pragma once

#include <vector>

class GOLInterface {
public:
	// Methods
	virtual ~GOLInterface() = default;
	virtual const std::vector<std::vector<CellState>>& getGridAsVector() const;
	virtual void toggleCell(int row, int col);
	virtual void stepForward();
	virtual void clear();
};