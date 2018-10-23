#include "StdAfx.h"
#include "BackgroundObject.h"


BackgroundObject::BackgroundObject(CString filename, int posx, int posy, int w, int h, double ss) : GraphicsObject(filename, posx, posy)
{
	height = h;
	width = w;
	scrollSpeed = ss;
}

void BackgroundObject::draw(HDC offScreenDC)
{
	CImage image; //The image needed
	int relativeX = (int)((x - mapPosition) * scrollSpeed) % width;
	//int relativeY = (int)((y - mapPositionY) * scrollSpeed) % height;

	image.Load(ID); //Loads in the image
	image.SetTransparentColor(RGB(255, 174, 201)); //Sets the pink to transparent for corresponding Red, Green, Blue values
	//This line draws it on the screen
	image.TransparentBlt(offScreenDC, relativeX, y, width, height, 0, 0, width, height);
	image.TransparentBlt(offScreenDC, relativeX + width, y, width, height, 0, 0, width, height);
	image.TransparentBlt(offScreenDC, relativeX - width, y, width, height, 0, 0, width, height);



	/*image.TransparentBlt(offScreenDC, relativeX, relativeY, width, height, 0, 0, width, height);
	image.TransparentBlt(offScreenDC, relativeX + width, relativeY - height, width, height, 0, 0, width, height);
	image.TransparentBlt(offScreenDC, relativeX - width, relativeY - height, width, height, 0, 0, width, height);*/


}

BackgroundObject::~BackgroundObject(void)
{
}
