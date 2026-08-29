#pragma once

#include "cellgrid.h"

#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/button.h>

class MainFrame : public wxFrame {
public:
	// Methods
	MainFrame(const wxString &title);
private:
	// Members
	wxPanel *mainPanel;
	wxBoxSizer *mainSizer;
	wxBoxSizer *controlSizer;

	wxButton *playButton;
	wxButton *stepForwardButton;
	wxButton *stepBackButton;
	wxButton *clearButton;
	CellGrid *cellGrid;
};