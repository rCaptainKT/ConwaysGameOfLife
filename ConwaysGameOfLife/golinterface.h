#pragma once

class GOLInterface {
public:
	virtual ~GOLInterface() = default;
	virtual void toggleCell(int row, int col);
	virtual void stepForward();
	virtual void clear();
};