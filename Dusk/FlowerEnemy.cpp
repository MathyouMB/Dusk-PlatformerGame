#include "stdafx.h"
#include "FlowerEnemy.h"




FlowerEnemy::FlowerEnemy() :Enemyobject("../pics/flower.png", 300, 388)
{
	enemyhealth = 15;
	xspeed = 13;
	yspeed = 0;

	movecount = 0;
	maxmovetime = 40;
	numBullets = 5;
	for (int i = 0; i < numBullets; i++)
	{
		bullets[i] = new BulletObject();
	}

	setMoveRight();
}

void FlowerEnemy::move(){

	//fireBullet(x + 100, y + 170, +20, +20);
	fireBullet(x +25 , y , +0, -20);


	y += yspeed;
	yspeed += GRAVITY;
	movecount++;

	if (onground)
	{

		yspeed = 0;
	}


	if (y > GROUND - height){
		y = GROUND - height;
		onground = true;

	}


	if (enemyhealth < 10) {
		movecount++;
		if (movecount <maxmovetime){
			x += xspeed;
			fireBullet(x + 100, y + 170, 0, +20);
		}
		else{
			xspeed = -xspeed;
			movecount = 0;

			if (state == MOVELEFT){
				fireBullet(x, y + 10, -20 + xspeed, 0);

				setMoveRight();
			}
			else{
				fireBullet(x, y + 10, 20 + xspeed, 0);
				setMoveLeft();
			}
		}
	}

	animate();

}

void FlowerEnemy::setMoveLeft()
{
	width = 64;
	height = 40;
	picY = 0;
	endCell = 0;
	loopCells = true;
	startCell = 0;

	state = MOVELEFT;
}

void FlowerEnemy::setMoveRight()
{
	width = 64;
	height = 40;
	picY = 0;
	endCell = 0;
	loopCells = true;
	startCell = 0;
	state = MOVERIGHT;
}



FlowerEnemy::~FlowerEnemy()
{
}
