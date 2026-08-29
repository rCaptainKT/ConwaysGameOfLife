#include <wx/wx.h>

#include "app.h"
#include "mainframe.h"
#include "gameoflife.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	GameOfLife gol = GameOfLife(30, 30);
	MainFrame *mainFrame = new MainFrame(gol);
	mainFrame->Show();
	mainFrame->SetFocus();
	return true;
}
