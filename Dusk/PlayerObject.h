#pragma once
#include "WeaponsObject.h"

#define MOVERIGHT 1
#define MOVELEFT 2
#define STANDLEFT 3
#define STANDRIGHT 4
#define JUMPRIGHT 5
#define JUMPLEFT 6
#define SHOOTRIGHT 7
#define SHOOTLEFT 8

class PlayerObject : public WeaponsObject
{
public:
	PlayerObject(void);
	int xspeed;
	int yspeed;
	int state;
	bool stoppedLeft;
	bool stoppedRight;
	void move();
	void setMoveRight();
	void setMoveLeft();
	void setStandRight();
	void setStandLeft();
	void setJumpRight();
	void setJumpLeft();
	void setShootRight();
	void setShootLeft();
	void onhit(BulletObject*);
	bool isJumping();
	~PlayerObject(void);
private:
	void setStand();
};

