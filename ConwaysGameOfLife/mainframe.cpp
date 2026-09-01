#include "mainframe.h"
#include "cellgrid.h"
#include "golinterface.h"

#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/grid.h>
#include <wx/event.h>
#include <wx/timer.h>

#define APP_NAME "Conway's Game Of Life"

MainFrame::MainFrame(GOLInterface &gol)
	: wxFrame(nullptr, wxID_ANY, APP_NAME)
	, gol(gol)
	, isPlaying(false)
	, playTimer(this) {
	// Create Main Widgets
	mainPanel = new wxPanel(this);
	mainSizer = new wxBoxSizer(wxHORIZONTAL);
	controlSizer = new wxBoxSizer(wxVERTICAL);

	// Create Control Buttons
	wxSize controlButtonSize = wxSize(200, 50);
	playButton = new wxButton(mainPanel, wxID_ANY, "Play", wxDefaultPosition, controlButtonSize);
	stepForwardButton = new wxButton(mainPanel, wxID_ANY, "Step Foward", wxDefaultPosition, controlButtonSize);
	stepBackButton = new wxButton(mainPanel, wxID_ANY, "Step Back", wxDefaultPosition, controlButtonSize);
	clearButton = new wxButton(mainPanel, wxID_ANY, "Clear", wxDefaultPosition, controlButtonSize);

	// Bind Control Buttons
	playButton->Bind(wxEVT_BUTTON, &MainFrame::onPlayButtonClick, this);
	stepForwardButton->Bind(wxEVT_BUTTON, &MainFrame::onStepForwardButtonClick, this);
	clearButton->Bind(wxEVT_BUTTON, &MainFrame::onClearButtonClick, this);

	// Bind Play Timer
	Bind(wxEVT_TIMER, &MainFrame::onPlayTimerNotify, this);

	// Set Control Sizer
	controlSizer->Add(playButton);
	controlSizer->Add(stepForwardButton);
	controlSizer->Add(stepBackButton);
	controlSizer->Add(clearButton);

	// Create Cell Grid
	wxSize cellSize = FromDIP(wxSize(25, 25));
	cellGrid = new CellGrid(this->gol, cellSize, mainPanel, wxID_ANY);

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

void MainFrame::onPlayButtonClick(wxCommandEvent &evt) {
	if (!isPlaying) {
		// Pressed play
		isPlaying = true;
		playButton->SetLabel("Stop");
		stepForwardButton->Disable();
		stepBackButton->Disable();
		playTimer.Start(100);
	} else {
		// Pressed stop
		playTimer.Stop();
		stepForwardButton->Enable();
		stepBackButton->Enable();
		playButton->SetLabel("Play");
		isPlaying = false;
	}
}

void MainFrame::onPlayTimerNotify(wxTimerEvent &evt) {
	onStepForwardEvent();
}

void MainFrame::onStepForwardButtonClick(wxCommandEvent &evt) {
	onStepForwardEvent();
}

void MainFrame::onClearButtonClick(wxCommandEvent &evt) {
	gol.clear();
	cellGrid->Refresh();
}

void MainFrame::onStepForwardEvent() {
	gol.stepForward();
	cellGrid->Refresh();
}