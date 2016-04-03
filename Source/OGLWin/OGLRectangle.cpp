#include "OGLRectangle.h"
#include <Windows.h>
#include <gl/GL.h>

OGLRectangle::OGLRectangle()
{

}

OGLRectangle::OGLRectangle(float x, float y, float height, float width, float r, float g, float b)
{
	m_topleft.SetX(x);
	m_topleft.SetY(y);
	m_bottomright.SetX(x + width);
	m_bottomright.SetY(y - height);

	m_width = width;
	m_height = height;

	m_x = x;
	m_y = y;

	m_r = r;
	m_g = g;
	m_b = b;
	
	m_clicked = false;
}

OGLRectangle::~OGLRectangle()
{

}

void OGLRectangle::Render()
{
	float tlx = m_topleft.GetX();
	float tly = m_topleft.GetY();
	float brx = m_bottomright.GetX();
	float bry = m_bottomright.GetY();

	//Draw a rectangle with psychedelic colour
	glBegin(GL_TRIANGLE_STRIP);								
	glColor3f(m_r, m_g, m_b);						
	glVertex2f(tlx, bry);										
	glVertex2f(brx, bry);										
	glVertex2f( tlx, tly);
	glVertex2f( brx, tly);

	glColor3f(1.0f, 1.0f, 1.0f);

	glEnd();
}

bool OGLRectangle::MouseMove( int x, int y )
{
	if (m_clicked)
	{
		m_topleft.SetX((float)x);
		m_topleft.SetY((float)y);
		m_bottomright.SetX((float)x + m_width);
		m_bottomright.SetY((float)y - m_height);

		//SetX(x);
		//SetY(y);
	}
	
	if (x >= m_topleft.GetX() && y <= m_topleft.GetY() && x <= m_bottomright.GetX() && y >= m_bottomright.GetY())
	{
		return true;
	}

	return false;
}

bool OGLRectangle::MouseLBUp( int x, int y )
{
	m_clicked = false;
	return true;
}

int OGLRectangle::MouseLBDown( int x, int y )
{
	if (x >= m_topleft.GetX() && y <= m_topleft.GetY() && x <= m_bottomright.GetX() && y >= m_bottomright.GetY())
	{
		m_clicked = true;
		return true;
	}

	return 0;
}

/****************************************************************************************************************************/
													// Accessors and Mutators
/****************************************************************************************************************************/

float OGLRectangle::GetX()
{
	return this->m_topleft.GetX();
}

void OGLRectangle::SetX(float x)
{
	this->m_topleft.SetX(x);
	this->m_bottomright.SetX(x + m_width);
}

float OGLRectangle::GetY()
{
	return this->m_topleft.GetY();
}

void OGLRectangle::SetY(float y)
{
	this->m_topleft.SetY(y);
	this->m_bottomright.SetY(y - m_height);
}

float OGLRectangle::GetHeight()
{
	return this->m_height;
}

void OGLRectangle::SetRGB(float r, float g, float b)
{
	m_r = r;
	m_g = g;
	m_b = b;
}
