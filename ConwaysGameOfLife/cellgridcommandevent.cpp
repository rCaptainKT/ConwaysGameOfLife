#include "cellgridcommandevent.h"

#include <wx/event.h>

CellGridCommandEvent::CellGridCommandEvent(wxEventType commandEventType, int id)
	:wxCommandEvent(commandEventType, id) {}

CellGridCommandEvent::CellGridCommandEvent(const CellGridCommandEvent &evt)
	:wxCommandEvent(evt) {}

wxEvent *CellGridCommandEvent::Clone() const {
	return new CellGridCommandEvent(*this);
}

int CellGridCommandEvent::getRow() {
	return this->row;
}

void CellGridCommandEvent::setRow(int row) {
	this->row = row;
}

int CellGridCommandEvent::getCol() {
	return this->col;
}

void CellGridCommandEvent::setCol(int col) {
	this->col = col;
}