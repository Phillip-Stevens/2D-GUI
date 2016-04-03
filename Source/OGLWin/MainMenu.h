#pragma once
#include "GUIWindow.h"
#include "GUIButton.h"
#include "GLFont.h"
#include "GUIItem.h"

class MainMenu : public GUIItem  
{
	private:

		// Name for the window and it's location which will be pre-determined!
		const char *m_windowName, *m_gameText, *m_optionsText, *m_exitText;
		float m_x, m_y;

		// Elements of the window
		GUIWindow *m_mainMenu;
		GUIButton *m_game, *m_options, *m_exit;

	public:
		MainMenu();
		~MainMenu();

		void Render();
		void RenderButtons();
		bool MouseMove(int x, int y);
		int MouseLBDown(int x, int y);
		bool MouseLBUp(int x, int y);
};

