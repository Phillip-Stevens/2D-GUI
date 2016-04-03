#pragma once

#include "GUITaskbar.h"
#include "GUIItem.h"
#include "OGLRectangle.h"
#include "GLFont.h"

// Inherit from GUIItem and overwride virtual methods
class GUIWindow: public GUIItem
{
private:
	// Colours
	float m_R, m_G, m_B;
	float m_width, m_height, m_x, m_y, m_barheight;
	float m_textX, m_textY;
	const char *m_winName;

	// Window Rectangle, Taskbar and the text for the window.
	OGLRectangle    *m_rect;
	OGLRectangle    *m_bar;
	GLFont		    *m_font;

	const char *m_buttonText;

public:
	GUIWindow(float x, float y, const char *name);
	~GUIWindow();

	void Render();

	void SetRectRGB(float r, float g, float b);
	void SetBarRGB(float r, float g, float b);
	void RenderText();
	void RenderWindow();

	bool MouseMove(int x, int y);
	int MouseLBDown(int x, int y);
	bool MouseLBUp(int x, int y);

	float GetX();
	float GetY();
	float getHeight();
	float getWidth();
};