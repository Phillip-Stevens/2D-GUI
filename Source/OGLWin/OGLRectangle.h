#pragma once

#include "Renderable.h"
#include "Listener.h"
#include "Vector2D.h"


class OGLRectangle : public Renderable, public Listener
{
	private:
		Vector2D		m_topleft;
		Vector2D		m_bottomright;

		// Colours
		float m_r, m_g, m_b;


		// Height, Width, X and Y
		float m_width, m_height, m_x, m_y;
		
		bool m_clicked;

	public:
						OGLRectangle();
						OGLRectangle(float x, float y, float height, float width, float r, float g, float b);
						~OGLRectangle();

		void			Render();
		bool			MouseMove( int x, int y );
		bool			MouseLBUp( int x, int y );
		int			MouseLBDown( int x, int y );

		void SetRGB(float r, float g, float b);
		
		float GetX();
		void SetX(float x);
		float GetY();
		void SetY(float y);
		float GetHeight();

};