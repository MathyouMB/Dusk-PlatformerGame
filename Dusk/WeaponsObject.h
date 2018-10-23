#pragma once
#include "GraphicsObject.h"
#include "BulletObject.h"


class WeaponsObject : public GraphicsObject
{
public:
	WeaponsObject(CString filename, int xpos, int ypos);
	int numBullets;
	BulletObject *bullets[50];
	void fireBullet(int x, int y, int xs, int ys);
	void drawBullets(HDC offScreenDC);
	void moveBullets();
	void checkBulletBlock(GraphicsObject* block);
	void checkBulletEntity(WeaponsObject* PlayerObject);
	void checkPlayerBlock(GraphicsObject* block);
	bool onground;
	virtual void onhit(BulletObject* b){};
	int xspeed;
	int yspeed;
	int prevX, prevY;
	~WeaponsObject(void);
};

