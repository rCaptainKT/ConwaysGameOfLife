#pragma once

#include <wx/button.h>

class Cell : public wxButton {
public:
	// Members
	int row;
	int col;

	// Methods
	Cell(int row, int col, wxWindow *parent, wxWindowID id, const wxString &label, const wxPoint &pos, const wxSize &size);
};