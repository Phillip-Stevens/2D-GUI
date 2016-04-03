#pragma once
#include "GUIWindow.h"
#include "GUIButton.h"
#include "GLFont.h"
#include "GUIItem.h"

class Options : public GUIItem
{
private:

	// Name for the window and it's location which will be pre-determined!
	const char *m_windowName, *m_applyText, *m_barText, *m_exitText;
	float m_x, m_y;

	// Elements of the window
	GUIWindow *m_optionsMenu;
	GUIButton *m_randomColour, *m_randomBar, *m_exit;

	float ran_r, ran_g, ran_b;


public:
	Options();
	~Options();

	void Render();
	void RenderButtons();
	bool MouseMove(int x, int y);
	int MouseLBDown(int x, int y);
	bool MouseLBUp(int x, int y);
};
