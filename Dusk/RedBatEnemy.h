#pragma once
#include "EnemyObject.h"
#define ANIMATELEFT 1
#define ANIMATERIGHT 2

class RedBatEnemy :
	public Enemyobject
{
public:


	virtual void move();
	void animateleft();
	void animateright();
	
	int state;
	int movecount;
	int maxmovetime;

	RedBatEnemy();
	~RedBatEnemy();
};