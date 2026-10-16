#include "cellgrid.h"
#include "cellstate.h"
#include "golinterface.h"

#include <wx/panel.h>
#include <wx/graphics.h>
#include <wx/dcbuffer.h>

CellGrid::CellGrid(GOLInterface &gol, wxSize &cellSize, wxWindow *parent, wxWindowID id,
	const wxPoint &pos, const wxSize &size, long style, const wxString &name)
	: wxPanel(parent, id, pos, size, style, name)
	, gol(gol)
	, cellSize(cellSize) {
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);
	this->Bind(wxEVT_PAINT, &CellGrid::onPaint, this);
	this->Bind(wxEVT_LEFT_DOWN, &CellGrid::onMouseDown, this);
	this->SetMinSize(wxSize(this->cellSize.GetWidth() * this->gol.getGridLength() + 3, this->cellSize.GetHeight() * this->gol.getGridHeight() + 3));
}

void CellGrid::onPaint(wxPaintEvent &evt) {
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();

	wxGraphicsContext *gc = wxGraphicsContext::Create(dc);
	if (gc) {
		wxPoint gridOrigin = this->FromDIP(wxPoint(0, 0));

		gc->SetPen(wxPen(wxColor(128, 128, 128), 1));
		for (int i = 0; i < this->gol.getGridHeight(); i++) {
			for (int j = 0; j < this->gol.getGridLength(); j++) {
				if (this->gol.getCellState(i, j) == this->gol.dead()) {
					gc->SetBrush(*wxTRANSPARENT_BRUSH);
				}else if (this->gol.getCellState(i, j) == this->gol.alive()) {
					gc->SetBrush(*wxBLACK_BRUSH);
				}
				gc->DrawRectangle(gridOrigin.x + (this->cellSize.GetWidth() * j), gridOrigin.y + (this->cellSize.GetHeight() * i), 
					this->cellSize.GetWidth(), this->cellSize.GetHeight());
			}
		}

		delete gc;
	}
}

void CellGrid::onMouseDown(wxMouseEvent &evt) {
	if (evt.GetButton() == wxMOUSE_BTN_LEFT) {
		wxPoint clickPos = evt.GetPosition();
		this->gol.toggleCellState(clickPos.y / this->cellSize.GetHeight(), clickPos.x / this->cellSize.GetWidth());
		Refresh();
	}
}

/*
* TODO:
* Propagate event to mainframe.
*/