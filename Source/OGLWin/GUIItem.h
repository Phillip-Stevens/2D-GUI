# pragma once

#include "Renderable.h"
#include "Listener.h"
#include <vector>
#include "Vector2D.h"
#include <algorithm> // allows for foreach loops

//Base class of a GUI item

class GUIItem : public Listener
{
	private:
		Vector2D		m_position;
		Renderable*		m_renderable; //the look of this GUI item, should be shared
		std::vector<GUIItem*> m_childitems;

		// Colours
		float m_R, m_G, m_B;

	public:
		GUIItem();
		virtual ~GUIItem();

		void AddItem(GUIItem*);
		void RemoveItem(GUIItem*);

		virtual void Render();
		virtual bool MouseMove ( int x, int y );
		virtual int MouseLBDown ( int x, int y );
		virtual bool MouseLBUp ( int x, int y );

		// Sets the RGB
		virtual void SetRGB(float r, float g, float b);

		/* Set/Get Position
		virtual float SetX(void) const;
		virtual void SetX(float x);
		virtual float GetY(void) const;
		virtual void SetY(float y);
		*/
		
};
