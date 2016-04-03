#pragma once

#include "OGLRectangle.h"
#include "GLFont.h"
#include "GUIItem.h"
//#include "Listener.h"

// Inherit from GUIItem and overwride virtual methods
class GUITaskbar : public GUIItem
{
private:

	// Position for the Text the text
	float m_textX, m_textY;

	// Colours of the task bar
	float m_R, m_G, m_B;

	// Settings/position for the rectangle
	float m_width, m_height, m_x, m_y;

	// Pointers to the rectangle and font
	OGLRectangle   *m_rect;
	GLFont		   *m_font;

	// Text for the taskbar
	const char *m_taskbarText;

public:
	GUITaskbar();
	GUITaskbar(float x, float y, float height, float width, const char *text);
	~GUITaskbar();

	void Render();

	void SetRectRGB(float r, float g, float b);
	void RenderText();

	bool MouseMove(int x, int y);
	int MouseLBDown(int x, int y);
	bool MouseLBUp(int x, int y);

	// Accessors and Mutators
	void SetX(float x);
	float GetX();
	void SetY(float y);
	float GetY();
	float GetHeight();

};