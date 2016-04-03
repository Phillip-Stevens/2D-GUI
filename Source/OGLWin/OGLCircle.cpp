#include "OGLCircle.h"
#include <Windows.h>
#include <gl/GL.h>

OGLCircle::OGLCircle()
{
	// Set X, Y and Rotation
	m_x.SetX(100);
	m_y.SetY(100);
	m_rot = 100.0f;

	// Set border colour
	m_br = 0.0f;
	m_bg = 0.0f;
	m_bb = 0.0f;

	// Set Forground colour
	m_fr = 1.0f;
	m_fg = 1.0f;
	m_fb = 1.0f;
}

OGLCircle::~OGLCircle()
{

}

void OGLCircle::Render()
{
	float x = m_x.GetX();
	float y = m_y.GetY();
	float r = m_rot;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(m_fr, m_fg, m_fb);
	for (int i = 0; i < 180; i++)
	{
		(float)x = r * (float)cos(i) - 100;
		(float)y = r * (float)sin(i) + 100;
		glVertex3f(x + 100, y - 100, 0);

		(float)x = r * (float)cos(i + 0.1) - 100;
		(float)y = r * (float)sin(i + 0.1) + 100;
		glVertex3f(x + 100, y - 100, 0);
	}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(m_br, m_bg, m_bb);
	for (int i = 0; i < 180; i++)
	{
		(float)x = r * (float)cos(i) - 20;
		(float)y = r * (float)sin(i) + 20;
		glVertex3f(x + 20, y - 20, 0);

		(float)x = r * (float)cos(i + 0.1) - 20;
		(float)y = r * (float)sin(i + 0.1) + 20;
		glVertex3f(x + 20, y - 20, 0);
	}
	glEnd();
}

bool OGLCircle::MouseMove(int x, int y)
{
	if (y > 0)
	{
		// Set border colour
		m_br += 0.01f;
		m_bg += 0.01f;
		m_bb += 0.01f;

		// Set Forground colour
		m_fr -= 0.01f;
		m_fg -= 0.01f;
		m_fb -= 0.01f;
	}
	return true;
}

bool OGLCircle::MouseLBUp(int x, int y)
{
	return true;
}

int OGLCircle::MouseLBDown(int x, int y)
{
	return true;
}
