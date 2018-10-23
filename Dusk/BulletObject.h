#pragma once
#include "GraphicsObject.h"

class BulletObject : public GraphicsObject
{
public:
	BulletObject(void);
	int xspeed;
	int yspeed;
	int distanceTravelled;
	int maxDistance;
	int damage;
	bool fired;
	void move();
	~BulletObject(void);
	bool exploding;
	void setexplode(bool side);
	void reset();

};
