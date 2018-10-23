#include "stdafx.h"
#include "RedBatEnemy.h"




RedBatEnemy::RedBatEnemy() :Enemyobject("../pics/bats.png", 700, 100)
{
	enemyhealth = 15;
	xspeed = 0;
	yspeed = 15;
	
	movecount = 0;
	maxmovetime = 20;
	numBullets = 1;
	for (int i = 0; i < numBullets; i++)
	{
		bullets[i] = new BulletObject();
	}

	animateleft();
}

void RedBatEnemy::move(){

	//fireBullet(x + 100, y + 170, +20, +20);
  fireBullet(x + 25, y, -20, 0);
	
	movecount++;



	if (movecount <maxmovetime){
			y += yspeed;
			
		}
		else{
			yspeed = -yspeed;
			movecount = 0;


		}


	animate();

}

void RedBatEnemy::animateleft()
{
	width = 105;
	height = 62;
	picY = 62; //312 for blue
	endCell = 2;
	loopCells = true;
	startCell = 0;

	state = ANIMATELEFT;
}

void RedBatEnemy::animateright()
{
	width = 64;
	height = 40;
	picY = 0;
	endCell = 0;
	loopCells = true;
	startCell = 0;
	state = ANIMATERIGHT;
}



RedBatEnemy::~RedBatEnemy()
{
}
