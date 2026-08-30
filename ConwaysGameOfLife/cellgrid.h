#pragma once

#include "cellstate.h"

#include <wx/panel.h>

/*
* DO NOT MOVE THE BELOW INCLUDE STATEMENT
* For reason unknown, moving it above the wxPanel include statement will cause the program to fail to compile.
* From the most recent compile attempt at the time of writing of this comment, it will produce 98 C4996 errors in wxcrt.h 
* and 24 warnings from various files not from this project.
* 
* I suspect it's either something to do with the file name or something Visual Studio is doing. 
* A test file with only the two statements below will still fail:
* #include "golinterface.h"
* #include <wx/panel.h>
* 
* But an copy of golinterface.h renamed to test.h will compile just fine:
* #include "test.h"
* #include <wx/panel.h>
*/
#include "golinterface.h"

class CellGrid : public wxPanel{
public:
	// Methods
	CellGrid(GOLInterface &gol, wxSize &cellSize, wxWindow *parent, wxWindowID id = wxID_ANY,
		const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize, long style = wxTAB_TRAVERSAL, 
		const wxString &name = wxPanelNameStr);
private:
	// Members
	GOLInterface &gol;
	wxSize cellSize;

	// Methods
	void onPaint(wxPaintEvent &evt);
	void onMouseDown(wxMouseEvent &evt);
};