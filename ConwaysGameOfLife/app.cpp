#include <wx/wx.h>

#include "app.h"
#include "mainframe.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	MainFrame *mainFrame = new MainFrame("Conway's Game Of Life");
	mainFrame->Show();
	mainFrame->SetFocus();
	return true;
}
