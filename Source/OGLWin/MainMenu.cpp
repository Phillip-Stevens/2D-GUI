#include "MainMenu.h"

MainMenu::MainMenu()
{
	m_windowName = "Main Menu";
	m_gameText = "Game";
	m_optionsText = "Options";
	m_exitText = "Exit";
	m_mainMenu = new GUIWindow(-300, 200, m_windowName);
	m_game = new GUIButton(0, 0, m_gameText);
	m_options = new GUIButton(0, 0, m_optionsText);
	m_exit = new GUIButton(0, 0, m_exitText);
}

MainMenu::~MainMenu()
{
	delete m_mainMenu;
	delete m_game;
	delete m_options;
	delete m_exit;
}

void MainMenu::Render()
{
	m_mainMenu->Render();
	RenderButtons();
}

void MainMenu::RenderButtons()
{
	// Obtain the position of the window to make sure the buttons maintian their place on the window
	float tempx, tempy;
	tempx = m_mainMenu->GetX();
	tempy = m_mainMenu->GetY();

	// Set the position depending on the locaiton of the window
	float offsetX = 79;
	float offsetY = 75;

	m_game->SetX(tempx - offsetX);
	m_game->SetY(tempy);
	m_options->SetX(tempx - offsetX);
	m_options->SetY(tempy - offsetY);
	m_exit->SetX(tempx - offsetX);
	m_exit->SetY(tempy - (offsetY * 2));
	
	// Call the Renders
	m_game->Render();
	m_options->Render();
	m_exit->Render();
}

bool MainMenu::MouseMove(int x, int y)
{
	m_mainMenu->MouseMove(x, y);
	m_game->MouseMove(x, y);
	m_options->MouseMove(x, y);
	m_exit->MouseMove(x, y);
	return false;
}

int MainMenu::MouseLBDown(int x, int y)
{
	m_mainMenu->MouseLBDown(x, y);

	// If the mouse button returns true we exit the program
	if (m_exit->MouseLBDown(x, y))
	{
		//this->~MainMenu();
		// exit the entire program
		std::exit(0);
		return 1; // fix it so it exits this loop
	}

	if(m_game->MouseLBDown(x, y))
	{
		// Return 2 to load up another menu in the future
		return 2;
	}

	if (m_options->MouseLBDown(x, y))
	{
		// Return 3 if we wish to open an options menu
		return 3;
	}
	
	return false;
}

bool MainMenu::MouseLBUp(int x, int y)
{
	m_mainMenu->MouseLBUp(x, y);
	m_game->MouseLBUp(x, y);
	m_options->MouseLBUp(x, y);
	m_exit->MouseLBUp(x, y);
	return false;
}
