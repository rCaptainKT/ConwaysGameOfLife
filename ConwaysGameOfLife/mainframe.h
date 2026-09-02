#pragma once

#include "cellgrid.h"
#include "golinterface.h"

#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/event.h>
#include <wx/timer.h>
#include <wx/hyperlink.h>

class MainFrame : public wxFrame {
public:
	// Methods
	MainFrame(GOLInterface &gol);
private:
	// Members
	wxBoxSizer *appSizer;
	wxPanel *appPanel;

	wxPanel *mainPanel;
	wxBoxSizer *mainSizer;
	wxBoxSizer *controlSizer;

	wxButton *playButton;
	wxButton *stepForwardButton;
	wxButton *stepBackButton;
	wxButton *clearButton;
	CellGrid *cellGrid;

	GOLInterface &gol;
	bool isPlaying;
	wxTimer playTimer;

	wxPanel *footerPanel;
	wxHyperlinkCtrl *repoLink;

	// Methods
	void onPlayButtonClick(wxCommandEvent &evt);
	void onPlayTimerNotify(wxTimerEvent &evt);
	void onStepForwardButtonClick(wxCommandEvent &evt);
	void onClearButtonClick(wxCommandEvent &evt);

	void onStepForwardEvent();
};