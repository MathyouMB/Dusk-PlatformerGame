#pragma once
class GraphicsObject
{
public:
	GraphicsObject(CString filename, int xpos, int ypos, int w = 54, int h = 42);
	CString ID;
	CImage image; //The image needed
	int height;
	int width;
	int x;
	int y;
	int picX;
	int picY;
	int curCell;
	int endCell;
	int startCell;
	bool loopCells;
	void draw(HDC offScreenDC);
	void animate();
	bool collide(GraphicsObject *target);
	~GraphicsObject(void);
};

