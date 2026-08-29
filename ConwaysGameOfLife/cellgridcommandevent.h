#pragma once

#include <wx/event.h>

wxDEFINE_EVENT(wxEVT_CELL_GRID_CLICK, wxCommandEvent);

class CellGridCommandEvent: public wxCommandEvent {
public:
	CellGridCommandEvent(wxEventType commandEventType = wxEVT_CELL_GRID_CLICK, int id = 0);
	CellGridCommandEvent(const CellGridCommandEvent &evt);
	wxEvent *Clone() const;
	int getRow();
	void setRow(int row);
	int getCol();
	void setCol(int col);
private:
	int row = 0;
	int col = 0;
};