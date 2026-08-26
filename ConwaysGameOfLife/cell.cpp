#include "cell.h"

#include <wx/button.h>

Cell::Cell(int row, int col, wxWindow *parent, wxWindowID id, const wxString &label, const wxPoint &pos, const wxSize &size) 
	: wxButton(parent, id, label, pos, size) {
	this->row = row;
	this->col = col;
}