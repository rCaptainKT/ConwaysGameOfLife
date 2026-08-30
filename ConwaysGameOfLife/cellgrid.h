#pragma once

#include "cellstate.h"
#include "golinterface.h"

#include <wx/panel.h>
#include <vector>

class CellGrid : public wxPanel{
public:
	// Methods
	CellGrid(GOLInterface &gol, wxSize &cellSize, wxWindow *parent, wxWindowID id = wxID_ANY,
		const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize, long style = wxTAB_TRAVERSAL, 
		const wxString &name = wxPanelNameStr);
private:
	// Members
	GOLInterface &gol;
	wxSize cellSize;

	// Methods
	void onPaint(wxPaintEvent &evt);
	void onMouseDown(wxMouseEvent &evt);
};