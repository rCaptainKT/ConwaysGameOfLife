#pragma once
#include "golinterface.h"

#include<wx/wx.h>

class App : public wxApp {
public:
	GOLInterface *gol;

	App();
	bool OnInit() override;
	int OnExit() override;
};