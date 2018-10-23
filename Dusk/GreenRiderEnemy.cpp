#include "stdafx.h"
#include "GreenRiderEnemy.h"



GreenRiderEnemy::GreenRiderEnemy() : Enemyobject("../pics/ridersized.png", 500, 388)
{
	enemyhealth = 5;
	xspeed = 5;
	yspeed = 0;
	movecount = 0;
	maxmovetime = 100;

	setMoveLeft();
}

void GreenRiderEnemy::move(){
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


	if (movecount <maxmovetime){
		x += xspeed;
	}
	else{
		xspeed = -xspeed;
		movecount = 0;
		if (state == MOVERIGHT){
			setMoveLeft();
		}
		else{
			setMoveRight();
		}
	}

	animate();

}


void GreenRiderEnemy::setMoveLeft()
{
	width = 140;
	height = 98;
	picY = 0;
	endCell = 4;
	loopCells = true;
	startCell = 0;

	state = MOVELEFT;
}

void GreenRiderEnemy::setMoveRight()
{
	width = 140;
	height = 98;
	picY = 98;
	endCell = 4;
	loopCells = true;
	startCell = 0;
	state = MOVERIGHT;
}



GreenRiderEnemy::~GreenRiderEnemy()
{
}
