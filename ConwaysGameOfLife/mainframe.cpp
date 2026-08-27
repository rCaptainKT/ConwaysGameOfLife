#include "mainframe.h"
#include "cellgrid.h"

#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/grid.h>
#include <vector>

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
	int gridLength = 30;
	int gridHeight = 30;
	
	// Create Main Widgets
	mainPanel = new wxPanel(this);
	mainSizer = new wxBoxSizer(wxHORIZONTAL);
	controlSizer = new wxBoxSizer(wxVERTICAL);
	//gridSizer = new wxGridSizer(gridLength, gridHeight, 0, 0);

	// Create Control Buttons
	wxSize controlButtonSize = wxSize(200, 50);
	playButton = new wxButton(mainPanel, wxID_ANY, "Play", wxDefaultPosition, controlButtonSize);
	stepForwardButton = new wxButton(mainPanel, wxID_ANY, "Step Foward", wxDefaultPosition, controlButtonSize);
	stepBackButton = new wxButton(mainPanel, wxID_ANY, "Step Back", wxDefaultPosition, controlButtonSize);
	resetButton = new wxButton(mainPanel, wxID_ANY, "Reset", wxDefaultPosition, controlButtonSize);

	// Set Control Sizer
	controlSizer->Add(playButton);
	controlSizer->Add(stepForwardButton);
	controlSizer->Add(stepBackButton);
	controlSizer->Add(resetButton);

	//// Create Grid Cells
	wxSize cellSize = wxSize(25, 25);
	CellGrid *cellGrid = new CellGrid(gridLength, gridHeight, cellSize, mainPanel, wxID_ANY);

	// Set Main Sizer
	mainSizer->Add(controlSizer, 0, wxALIGN_CENTER);
	mainSizer->Add(cellGrid, 0, wxALIGN_CENTER);
	mainPanel->SetSizer(mainSizer);
	mainSizer->Fit(mainPanel);
	mainSizer->SetSizeHints(this);

	// Set Frame
	//SetClientSize(800, 800);
	Center();
}