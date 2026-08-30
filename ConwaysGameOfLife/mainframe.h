#pragma once

#include "cellgrid.h"
#include "golinterface.h"

#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/event.h>

class MainFrame : public wxFrame {
public:
	// Methods
	MainFrame(GOLInterface &gol);
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

	GOLInterface &gol;

	// Methods
	void onStepForwardButtonClick(wxCommandEvent &evt);
};