#include "Options.h"

Options::Options()
{
	m_windowName = "Options Menu";
	m_applyText = "Random";
	m_barText = "Title";
	m_exitText = "Exit";
	m_optionsMenu = new GUIWindow(100, 200, m_windowName);
	m_randomBar = new GUIButton(0, 0, m_barText);
	m_randomColour = new GUIButton(0, 0, m_applyText);
	m_exit = new GUIButton(0, 0, m_exitText);

	ran_r = 0.1f;
	ran_g = 0.1f;
	ran_b = 0.1f;
}

Options::~Options()
{
	delete m_optionsMenu;
	delete m_randomBar;
	delete m_randomColour;
	delete m_exit;
}

void Options::Render()
{
	m_optionsMenu->Render();
	RenderButtons();
}

void Options::RenderButtons()
{
	float tempx, tempy;
	tempx = m_optionsMenu->GetX();
	tempy = m_optionsMenu->GetY();

	// Set the position depending on the locaiton of the window
	float offsetX = 79;
	float offsetY = 75;

	m_randomBar->SetX(tempx - offsetX);
	m_randomBar->SetY(tempy);
	m_randomColour->SetX(tempx - offsetX);
	m_randomColour->SetY(tempy - offsetY);
	m_exit->SetX(tempx - offsetX);
	m_exit->SetY(tempy - (offsetY * 2));

	// Call the Renders
	m_randomBar->Render();
	m_randomColour->Render();
	m_exit->Render();
}

bool Options::MouseMove(int x, int y)
{
	m_optionsMenu->MouseMove(x, y);
	m_randomColour->MouseMove(x, y);
	m_randomBar->MouseMove(x, y);
	m_exit->MouseMove(x, y);
	return false;

}

int Options::MouseLBDown(int x, int y)
{
	m_optionsMenu->MouseLBDown(x, y);

	if (m_randomBar->MouseLBDown(x, y))
	{
		ran_r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		ran_g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		ran_b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		m_optionsMenu->SetBarRGB(ran_r, ran_g, ran_b);
	}

	if (m_randomColour->MouseLBDown(x, y))
	{
		ran_r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		ran_g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		ran_b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		m_optionsMenu->SetRectRGB(ran_r, ran_g, ran_b);
	}
	if (m_exit->MouseLBDown(x, y))
	{
		// returns 5 to close the window down again
		return 5;
	}

	return false;
}

bool Options::MouseLBUp(int x, int y)
{
	m_optionsMenu->MouseLBUp(x, y);
	m_randomColour->MouseLBUp(x, y);
	m_randomBar->MouseLBUp(x, y);
	m_exit->MouseLBUp(x, y);
	return false;
}
