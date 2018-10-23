#include "StdAfx.h"
#include "BulletObject.h"
#include <math.h>

BulletObject::BulletObject(void) : GraphicsObject("../pics/PurpleFire.bmp", 0, 0)
{
	fired = false;
	height = 13;
	width = 13 ;
	distanceTravelled = 0;
	maxDistance = 500;
	xspeed = 0;
	yspeed = 0;
	exploding = false;
	damage = 1;
}

void BulletObject::move()
{

	animate();
	if (exploding){
		if (curCell == endCell){
			reset();
		}
	}
	else{

		x += xspeed;
		y += yspeed;
		distanceTravelled += abs(xspeed) + abs(yspeed);

		if (distanceTravelled > maxDistance)
		{
			reset();
		}
	}
}
void BulletObject::reset(){
	exploding = false;
	fired = false;
	curCell = 0;
	x = 0;
	y = 0;
	picY = 0;
	picX = 0;
	width = 13;
	height = 13;
	distanceTravelled = 0;
	endCell = 0;

}

void BulletObject::setexplode(bool side)
{
	width = 32;
	height = 32;
	picY = 13;
	picX = 0;

	x -= 15;
	y -= 15;
	xspeed = 0;
	yspeed = 0;
	exploding = true;
	endCell = 2;
	loopCells = false;
	curCell = 0;
}
BulletObject::~BulletObject(void)
{
}
