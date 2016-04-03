#include "GUITaskbar.h"

GUITaskbar::GUITaskbar()
{
	float x = 0;
	float y = 0;
	float height = 25;
	float width = 300;

	m_x = x;
	m_y = y;
	m_height = height;
	m_width = width;

	m_rect = new OGLRectangle(m_x, m_y, m_height, m_width, 1, 1, 1);
}

GUITaskbar::GUITaskbar(float x, float y, float height, float width, const char *text)
{
	this->m_x = x;
	this->m_y = y;
	this->m_height = height;
	this->m_width = width;

	m_rect = new OGLRectangle(x, y, height, width, 1, 0, 1);
}

GUITaskbar::~GUITaskbar()
{
}

void GUITaskbar::Render()
{
	m_rect->Render();
}

bool GUITaskbar::MouseMove(int x, int y)
{
	m_rect->MouseMove(x, y);
	return false;
}

int GUITaskbar::MouseLBDown(int x, int y)
{
	m_rect->MouseLBDown(x, y);
	return false;
}

bool GUITaskbar::MouseLBUp(int x, int y)
{
	m_rect->MouseLBUp(x, y);
	return false;
}

float GUITaskbar::GetHeight()
{
	return this->m_height;
}

void GUITaskbar::SetRectRGB(float r, float g, float b)
{
	m_rect->SetRGB(r, g, b);
}
