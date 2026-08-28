#include "cellgrid.h"
#include "gameoflife.h"

#include <wx/panel.h>
#include <wx/graphics.h>
#include <wx/dcbuffer.h>
#include <vector>

CellGrid::CellGrid(int cellLength, int cellHeight, wxSize &cellSize, wxWindow *parent, wxWindowID id, 
	const wxPoint &pos, const wxSize &size, long style, const wxString &name)
	: wxPanel(parent, id, pos, size, style, name) {
	this->gridLength = cellLength;
	this->gridHeight = cellHeight;
	this->cellSize = cellSize;
	this->grid = std::vector<std::vector<CellState>>(cellHeight, std::vector<CellState>(cellLength, CellState::DEAD));

	this->SetBackgroundStyle(wxBG_STYLE_PAINT);
	this->Bind(wxEVT_PAINT, &CellGrid::onPaint, this);
	this->Bind(wxEVT_LEFT_DOWN, &CellGrid::mouseDown, this);
	this->SetMinSize(wxSize(this->cellSize.GetWidth()*gridLength+3, this->cellSize.GetHeight()*gridHeight+3));
}

void CellGrid::onPaint(wxPaintEvent &evt) {
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();

	wxGraphicsContext *gc = wxGraphicsContext::Create(dc);
	if (gc) {
		wxPoint gridOrigin = this->FromDIP(wxPoint(0, 0));

		gc->SetPen(wxPen(wxColor(128, 128, 128), 1));
		for (int i = 0; i < this->gridHeight; i++) {
			for (int j = 0; j < this->gridLength; j++) {
				if (this->grid.at(i).at(j) == CellState::DEAD) {
					gc->SetBrush(*wxTRANSPARENT_BRUSH);
				}else if (this->grid.at(i).at(j) == CellState::ALIVE) {
					gc->SetBrush(*wxBLACK_BRUSH);
				}
				gc->DrawRectangle(gridOrigin.x + (this->cellSize.GetWidth() * j), gridOrigin.y + (this->cellSize.GetHeight() * i), 
					this->cellSize.GetWidth(), this->cellSize.GetHeight());
			}
		}

		delete gc;
	}
}

void CellGrid::mouseDown(wxMouseEvent &evt) {
	if (evt.GetButton() == wxMOUSE_BTN_LEFT) {
		wxPoint clickPos = evt.GetPosition();
		CellState &cell = this->grid.at(clickPos.y / this->cellSize.GetHeight()).at(clickPos.x / this->cellSize.GetWidth());
		if (cell == CellState::DEAD) {
			cell = CellState::ALIVE;
		}else if (cell == CellState::ALIVE) {
			cell = CellState::DEAD;
		}
		Refresh();
	}
}