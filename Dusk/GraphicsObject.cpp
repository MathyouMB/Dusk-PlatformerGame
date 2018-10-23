#include "StdAfx.h"
#include "atlstr.h" // added cause of cstring
#include "GraphicsObject.h"


GraphicsObject::GraphicsObject(CString filename, int xpos, int ypos, int w, int h)
{
	ID = filename;
	width = w;
	height = h;
	x = xpos;
	y = ypos;
	picY = 0;
	picX = 0;
	curCell = 0;
	endCell = 0;
	startCell = 0;
	loopCells = true;
	image.Load(ID); //Loads in the image
}

void GraphicsObject::draw(HDC offScreenDC)
{
	image.SetTransparentColor(RGB(255, 174, 201)); //Sets the pink to transparent for corresponding Red, Green, Blue values
	//This line draws it on the screen
	image.TransparentBlt(offScreenDC, //Destination DC
		x - mapPosition, //X position of the Destination DC
	    y,//y-mapPositionY, //Y position of the Destination DC      y,
		width, //Width of the Destination DC
		height, //Height of the Destination DC
		picX, //X position of the Source DC
		picY, //Y position of the Source DC
		width, //Width of the Source DC
		height);  //Height of the Source DC
}

void GraphicsObject::animate()
{
	//updates the current cell
	curCell += 1;
	//loop back to the beginning
	if (curCell >= endCell)
	{
		if (loopCells == true)
		{
			curCell = startCell;
		}
		else
		{
			curCell = endCell;
		}
	}
	//update the drawing position
	picX = width * curCell;
}


bool GraphicsObject::collide(GraphicsObject* target)
{
	if (x <= target->x + target->width && x + width >= target->x){
		if (y <= target->y + target->height && y + height >= target->y){
			return true;
		}
	}
	return false;
}
GraphicsObject::~GraphicsObject(void)
{
}
