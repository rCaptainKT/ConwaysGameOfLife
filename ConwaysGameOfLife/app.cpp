#include <wx/wx.h>

#include "app.h"
#include "mainframe.h"
#include "gameoflife.h"

wxIMPLEMENT_APP(App);

App::App()
	:gol (new GameOfLife(30, 30)) {}

bool App::OnInit() {
	MainFrame *mainFrame = new MainFrame(*gol);
	mainFrame->Show();
	mainFrame->SetFocus();
	return true;
}

int App::OnExit() {
	delete gol;
	return wxApp::OnExit();
}
