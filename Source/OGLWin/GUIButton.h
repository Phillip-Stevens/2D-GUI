#pragma once

#include "OGLRectangle.h"
#include "GLFont.h"
#include "GUIItem.h"
//#include "Listener.h"

// Inherit from GUIItem and overwride virtual methods
class GUIButton : public GUIItem
{
	private:

		// Variables for the text
		float m_textX, m_textY;

		// Colours
		float m_R, m_G, m_B;
		float m_hoverR, m_hoverG, m_hoverB;
		float m_clickR, m_clickG, m_clickB;

		// Width, Height, X and Y.
		float m_width, m_height,  m_x, m_y;
		bool m_clicked;

		OGLRectangle   *m_rect;
		GLFont		   *m_font;

		const char *m_buttonText;

	public:
		GUIButton(float x, float y, const char *text);
		~GUIButton();

		void Render();

		void SetRectRGB(float r, float g, float b);
		void RenderText();

		bool MouseMove(int x, int y);
		int MouseLBDown(int x, int y);
		bool MouseLBUp(int x, int y);	

		float GetX();
		void SetX(float x);
		float GetY();
		void SetY(float y);
};