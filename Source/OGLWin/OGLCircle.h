#pragma once

#include "Renderable.h"
#include "Listener.h"
#include "Vector2D.h"

class OGLCircle : public Renderable, public Listener
{
	private:
		Vector2D m_x;
		Vector2D m_y;
		float m_rot;

		// floats to store colours (b border, f foreground)
		float m_br, m_bg, m_bb;
		float m_fr, m_fg, m_fb;

	public:
		OGLCircle();
		~OGLCircle();

		void Render();
		bool MouseMove(int x, int y);
		bool MouseLBUp(int x, int y);
		int MouseLBDown(int x, int y);
};