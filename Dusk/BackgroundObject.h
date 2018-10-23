#pragma once
#include "GraphicsObject.h"

class BackgroundObject : public GraphicsObject
{
public:
	BackgroundObject(CString filename, int posx, int posy, int w, int h, double ss);
	double scrollSpeed;
	void draw(HDC offScreenDC);
	~BackgroundObject(void);
};

