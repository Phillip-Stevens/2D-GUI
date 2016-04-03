#include "GUIButton.h"

GUIButton::GUIButton(float x, float y, const char *text)
{
	m_x = x;
	m_y = y;
	m_width = 150.0f;
	m_height = 50.0f;

	// Colours for the rectangle default, clicked and hover!
	m_R = 0.1f;
	m_G = 0.1f;
	m_B = 1.0f;
	
	m_clickR = 1.0f;
	m_clickG = 0.1f;
	m_clickB = 0.1f;

	m_hoverR = 0.1f;
	m_hoverG = 1.0f;
	m_hoverB = 0.1f;
	
	// Create the rectangle and the Text
	m_rect = new OGLRectangle(m_x, m_y, m_height, m_width, m_R, m_G, m_B);

	m_font = new GLFont();
	m_font->Create("franklin_gothic.glf");
	m_buttonText = text;

	m_clicked = false;
}

GUIButton::~GUIButton()
{
	delete m_rect;
	delete m_font;
}


void GUIButton::Render()
{
	// Render the Rectangle
	m_rect->Render();
	RenderText();
}

void GUIButton::RenderText()
{
	// Render the text to the center of the button
	m_textX = (m_rect->GetX() + (m_width / 3.5f));
	m_textY = (m_rect->GetY() - (m_height / 4.5f));


	// Render Text
	m_font->Begin();
	m_font->RenderText(m_buttonText, m_textX, m_textY, 0, 10);
	m_font->End();
}

/****************************************************************************************************************************/
												// Listener Actions
/****************************************************************************************************************************/

bool GUIButton::MouseMove(int x, int y)
{
	if (m_rect->MouseLBDown(x, y))
	{
		m_rect->SetRGB(m_hoverR, m_hoverG, m_hoverB);
		return true;
	}
	else
	{
		m_rect->SetRGB(m_R, m_G, m_B);
	}
	return false;
}

int GUIButton::MouseLBDown(int x, int y)
{
	if (m_rect->MouseLBDown(x, y))
	{
		m_rect->SetRGB(m_clickR, m_clickG, m_clickB);
		return true;
	}
	return false;
}

bool GUIButton::MouseLBUp(int x, int y)
{
	if (m_rect->MouseLBUp(x, y))
	{
		this->MouseMove(x, y);		
	}

	return false;
}

/****************************************************************************************************************************/
														// Accessors and Mutators
/****************************************************************************************************************************/

float GUIButton::GetX()
{
	return m_rect->GetX();
}

void GUIButton::SetX(float x)
{
	m_rect->SetX(x + m_width);
}

float GUIButton::GetY()
{
	return m_rect->GetY();
}

void GUIButton::SetY(float y)
{
	m_rect->SetY(y - m_height);
}

void GUIButton::SetRectRGB(float r, float g, float b)
{
	m_rect->SetRGB(r, g, b);
}
