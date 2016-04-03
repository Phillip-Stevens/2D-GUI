#include "GUIWindow.h"

GUIWindow::GUIWindow(float x, float y, const char *name)
{
	// Set the X, Y, Width and Height (static size for now)
	m_x = x;
	m_y = y;
	m_height = 300;
	m_width = 300;
	m_barheight = 25;

	// Create the Window and it's "name"
	m_rect = new OGLRectangle(m_x, m_y, m_height, m_width, 1.0f, 1.0f, 1.0f);
	m_bar = new OGLRectangle(m_x, m_y, m_barheight, m_width, 0.0f, 0.5f, 0.5f);
	m_font = new GLFont();
	m_font->Create("franklin_gothic.glf");
	m_winName = name; // Set this to the text that's passed in!
}

GUIWindow::~GUIWindow()
{
	delete m_rect;
	delete m_bar;
	delete m_font;
}

/****************************************************************************************************************************/
												// Render Methods
/****************************************************************************************************************************/

void GUIWindow::Render()
{
	// Render the Bar
	RenderWindow();
	m_bar->Render();
	RenderText();
}

void GUIWindow::SetRectRGB(float r, float g, float b)
{
	m_rect->SetRGB(r, g, b);
}

void GUIWindow::SetBarRGB(float r, float g, float b)
{
	m_bar->SetRGB(r, g, b);
}

// Handles Rendering Text
void GUIWindow::RenderText()
{
	// Render the text to the center of the button
	m_textX = (m_bar->GetX() + 5.0f);
	m_textY = (m_bar->GetY() + 2.0f);


	// Render Text
	m_font->Begin();
	m_font->RenderText(m_winName, m_textX, m_textY, 0, 10);
	m_font->End();
}

void GUIWindow::RenderWindow()
{
	// Render the window to the bars x and y position
	m_rect->SetX(m_bar->GetX());
	m_rect->SetY(m_bar->GetY());

	m_rect->Render();
}

/****************************************************************************************************************************/
													// Listener Methods														 
/****************************************************************************************************************************/

bool GUIWindow::MouseMove(int x, int y)
{
	m_bar->MouseMove(x, y);
	//m_rect->MouseMove(x, y);
	return false;
}

int GUIWindow::MouseLBDown(int x, int y)
{
	m_bar->MouseLBDown(x, y);
	//m_rect->MouseLBDown(x, y);
	return false;
}

bool GUIWindow::MouseLBUp(int x, int y)
{
	m_bar->MouseLBUp(x, y);
	//m_rect->MouseLBUp(x, y);
	return false;
}

float GUIWindow::GetX()
{
	return m_rect->GetX();
}

float GUIWindow::GetY()
{
	return m_rect->GetY();
}

float GUIWindow::getHeight()
{
	return this->m_height;
}

float GUIWindow::getWidth()
{
	return this->m_width;
}
