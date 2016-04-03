#include "GUIItem.h"

GUIItem::GUIItem()
{
	m_renderable = NULL;
}

GUIItem::~GUIItem()
{
	//TODO: Free up resource on delete
	//Q: Can you delete m_renderable if the renderable is shared by other GUI items?
	//GUIItem->AddItem(rect);
	//ProprtyAddItem(GUIItem item)
	//{
		//m_childitems.pushback(item);
	//}

}

void GUIItem::Render()
{
	for (int i = 0; i < m_childitems.size(); i++)
	{
		m_childitems[i]->Render();
	}
}

void GUIItem::AddItem(GUIItem* item)
{
	// Add item to the list
	m_childitems.push_back(item);
}

void GUIItem::RemoveItem(GUIItem* item)
{
	for (int i = 0; i < m_childitems.size(); i++)
	{
		m_childitems.erase(std::remove(m_childitems.begin(), m_childitems.end(), item), m_childitems.end());
	}
}

bool GUIItem::MouseMove(int x, int y)
{
	for (int i = 0; i < m_childitems.size(); i++) 
	{
		m_childitems[i]->MouseMove(x, y);
	}
	return true;
}

int GUIItem::MouseLBDown(int x, int y)
{
	for (int i = 0; i < m_childitems.size(); i++)
	{
		m_childitems[i]->MouseLBDown(x, y);
	}
	return 0;
}

bool GUIItem::MouseLBUp(int x, int y)
{
	for (int i = 0; i < m_childitems.size(); i++)
	{
		m_childitems[i]->MouseLBUp(x, y);
	}

	return true;
}

void GUIItem::SetRGB(float r, float g, float b)
{
	m_R = r;
	m_G = g;
	m_B = b;
}

