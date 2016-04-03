#include "WindowManager.h"

WindowManager* WindowManager::s_wndmgr = NULL;

WindowManager::WindowManager()
{
	m_mainMenu = new MainMenu();
	m_guilist.push_back(m_mainMenu);
	m_optionsCreated = false;
	s_wndmgr = NULL;
}

WindowManager::~WindowManager()
{
	//Cleanup other stuff if necessary
	m_guilist.empty();
	delete s_wndmgr;
	delete m_mainMenu;
}

void WindowManager::Create()
{
	if ( !s_wndmgr ) s_wndmgr = new WindowManager();
}

void WindowManager::Destroy()
{
	if ( s_wndmgr ) delete s_wndmgr;
}

void WindowManager::Render()
{
	for (int i = 0; i < m_guilist.size(); i++)
	{
		m_guilist[i]->Render();
	}
}

void WindowManager::MouseMove(float x, float y)
{
	for (int i = 0; i < m_guilist.size(); i++)
	{
		m_guilist[i]->MouseMove(x, y);
	}
}

void WindowManager::MouseLBDown(float x, float y)
{
	for (int i = 0; i < m_guilist.size(); i++)
	{
		int action = 0;
		action = m_guilist[i]->MouseLBDown(x, y);
		SwitchBoard(action);
	}
}

void WindowManager::SwitchBoard(int option)
{
	switch (option)
	{
		case 2:
			break;
		case 3:
			if (!m_optionsCreated)
			{
				m_optionsMenu = new Options();
				m_guilist.push_back(m_optionsMenu);
				m_optionsCreated = true;
			}
			break;
		case 4:
			break;
		case 5:
			m_optionsMenu->~Options();
			m_guilist.push_back(m_optionsMenu);
			m_optionsCreated = false;
			break;
	}
}

void WindowManager::MouseLBUp(float x, float y)
{
	for (int i = 0; i < m_guilist.size(); i++)
	{
		m_guilist[i]->MouseLBUp(x, y);
	}
}

void WindowManager::AddItem(GUIItem* item)
{
	if (std::find(m_guilist.begin(), m_guilist.end(), item) != m_guilist.end())
	{
		// if its found do nothing
	}
	else
	{
		m_guilist.push_back(item);
	}
}

void WindowManager::RemoveItem(GUIItem* item)
{
	if (std::find(m_guilist.begin(), m_guilist.end(), item) != m_guilist.end())
	{
		// if its found do nothing
	}
	else
	{
		m_guilist.pop_back();
	}
}
