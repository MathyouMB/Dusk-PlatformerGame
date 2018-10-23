#pragma once
#include "EnemyObject.h"
#define MOVERIGHT 1
#define MOVELEFT 2

class FlowerEnemy :
	public Enemyobject
{
public:


	virtual void move();
	void setMoveRight();
	void setMoveLeft();
	int state;
	int movecount;
	int maxmovetime;

	FlowerEnemy();
	~FlowerEnemy();
};