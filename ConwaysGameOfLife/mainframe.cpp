#include "mainframe.h"

#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/button.h>

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
	mainPanel = new wxPanel(this);
	mainSizer = new wxBoxSizer(wxHORIZONTAL);
	controlSizer = new wxBoxSizer(wxVERTICAL);
	gridSizer = new wxGridSizer(20, 20, 10, 10);

	// Create Control Buttons
	playButton = new wxButton(mainPanel, wxID_ANY, "Play", wxDefaultPosition, wxSize(300, 100));
	stepForwardButton = new wxButton(mainPanel, wxID_ANY, "Step Foward", wxDefaultPosition, wxSize(300, 100));
	stepBackButton = new wxButton(mainPanel, wxID_ANY, "Step Back", wxDefaultPosition, wxSize(300, 100));
	resetButton = new wxButton(mainPanel, wxID_ANY, "Reset", wxDefaultPosition, wxSize(300, 100));

	// Set Control Sizer
	controlSizer->Add(playButton);
	controlSizer->Add(stepForwardButton);
	controlSizer->Add(stepBackButton);
	controlSizer->Add(resetButton);

	// Set Main Sizer
	mainSizer->Add(controlSizer);
	mainSizer->Add(gridSizer);
	mainPanel->SetSizer(mainSizer);
	mainSizer->SetSizeHints(this);

	// Set Frame
	SetClientSize(800, 800);
	Center();
}