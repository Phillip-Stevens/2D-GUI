#pragma once

class Listener
{
	public:
		virtual bool MouseMove ( int x, int y ) = 0;
		virtual int MouseLBDown ( int x, int y ) = 0;
		virtual bool MouseLBUp ( int x, int y ) = 0;
};