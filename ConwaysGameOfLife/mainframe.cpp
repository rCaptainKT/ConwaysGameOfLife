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
#include <wx/hyperlink.h>

#define APP_NAME "Conway's Game Of Life"
#define REPO_LINK "https://github.com/rCaptainKT/ConwaysGameOfLife"

MainFrame::MainFrame(GOLInterface &gol)
	: wxFrame(nullptr, wxID_ANY, APP_NAME)
	, gol(gol)
	, isPlaying(false)
	, isClearReset(false)
	, playTimer(this) {
	// Create App Sizer
	appSizer = new wxBoxSizer(wxVERTICAL);
	appPanel = new wxPanel(this);

	// Create Main Widgets
	mainPanel = new wxPanel(appPanel);
	mainSizer = new wxBoxSizer(wxHORIZONTAL);
	controlSizer = new wxBoxSizer(wxVERTICAL);

	// Create Control Buttons
	wxSize controlButtonSize = wxSize(200, 50);
	playButton = new wxButton(mainPanel, wxID_ANY, "Play", wxDefaultPosition, controlButtonSize);
	stepForwardButton = new wxButton(mainPanel, wxID_ANY, "Step Foward", wxDefaultPosition, controlButtonSize);
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
	controlSizer->Add(clearButton);

	// Create Cell Grid
	wxSize cellSize = FromDIP(wxSize(25, 25));
	cellGrid = new CellGrid(this->gol, cellSize, mainPanel, wxID_ANY);

	// Set Main Sizer
	mainSizer->Add(controlSizer, 0, wxALIGN_CENTER);
	mainSizer->Add(cellGrid, 0, wxALIGN_CENTER);
	mainPanel->SetSizer(mainSizer);
 
	// Create Footer Panel
	footerPanel = new wxPanel(appPanel);
	repoLink = new wxHyperlinkCtrl(footerPanel, wxID_ANY, "Github", REPO_LINK);

	// Set App Sizer
	appSizer->Add(mainPanel, 0, wxALIGN_CENTER);
	appSizer->Add(footerPanel, 0, wxALIGN_LEFT | wxALL, 3);
	appPanel->SetSizer(appSizer);
	appSizer->SetSizeHints(this);
	 
	// Set Frame
	SetClientSize(DoGetBestClientSize());
	Center();
}

void MainFrame::onPlayButtonClick(wxCommandEvent &evt) {
	if (!isPlaying) {
		// Pressed play
		isPlaying = true;
		playButton->SetLabel("Stop");
		stepForwardButton->Disable();
		playTimer.Start(100);
	} else {
		// Pressed stop
		playTimer.Stop();
		stepForwardButton->Enable();
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
	if (!isClearReset) {
		gol.clear();
	} else {
		gol.loadGridState();
	}
	updateClearButton();
	cellGrid->Refresh();
}

void MainFrame::onStepForwardEvent() {
	gol.stepForward();
	updateClearButton();
	cellGrid->Refresh();
}

void MainFrame::updateClearButton() {
	if (gol.getIsModified()) {
		isClearReset = true;
		clearButton->SetLabel("Reset");
	} else {
		isClearReset = false;
		clearButton->SetLabel("Clear");
	}
}