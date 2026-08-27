#pragma once

#include <wx/panel.h>

#include <vector>

enum class CellState {
	DEAD,
	ALIVE
};

class CellGrid : public wxPanel{
public:
	// Methods
	CellGrid(int gridLength, int gridHeight, wxSize &cellSize, wxWindow *parent, wxWindowID id = wxID_ANY, const wxPoint &pos = wxDefaultPosition, 
		const wxSize &size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString &name = wxPanelNameStr);
private:
	// Members
	int gridLength;
	int gridHeight;
	wxSize cellSize;
	std::vector<std::vector<CellState>> grid;

	// Methods
	void onPaint(wxPaintEvent &evt);
	//void mouseDown(wxMouseEvent &evt);s
};