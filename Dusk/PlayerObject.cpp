#include "StdAfx.h"
#include "PlayerObject.h"


PlayerObject::PlayerObject(void) : WeaponsObject("../pics/player1.png", 100, 100)
{
	setStandRight();
	xspeed = 0;
	yspeed = 0;
	
	state = STANDRIGHT;
	numBullets = 10;
	for (int i = 0; i < numBullets; i++)
	{
		bullets[i] = new BulletObject();
	}
}

void PlayerObject::onhit(BulletObject* b){
	x += b->xspeed;
	x = 100;
	y = 100;
	mapPosition = 0;
}

void PlayerObject::move()
{
	prevX = x;
	prevY = y;
	x += xspeed;
	y += yspeed;
	yspeed += GRAVITY;


	if (onground)
	{
		setStand();
		yspeed = 0;
	}

	if (y > GROUND - height){
		y = GROUND - height;
		onground = true;
		setStand();
	}
	if ((x - mapPosition < 450 && xspeed < 0) || (x - mapPosition > 450 && xspeed > 0))
	{
		mapPosition += xspeed;
	}
	/*if ((y - mapPositionY < 100 && yspeed < 0) || (y - mapPositionY >350 && yspeed >0)){
	mapPositionY += yspeed;
	}*/

	animate();
}

void PlayerObject::setMoveRight()
{
	////width of each cell
	//width = 56;
	////height of each cell
	//height = 72;
	////the Y position in the sprite strip
	//picY = 0;
	////the last cell or the number of cells
	//endCell = 9;
	////whether to loop through cells
	//loopCells = true;
	////the cell to start at
	//startCell = 1;
	////the speed of victor (not related to animation)
	//xspeed = 10;
	///*picX=0;*/
	////victor’s new state
	//state = MOVERIGHT;

	width = 56;
	height = 63;
	picY = 0;
	endCell = 4;
	loopCells = true;
	startCell = 0;
	xspeed = 15;
	state = MOVERIGHT;


}

void PlayerObject::setMoveLeft()
{
	width = 56;
	height = 63;
	picY = 63;
	endCell = 4;
	loopCells = true;
	startCell = 0;
	xspeed = -15;
	state = MOVELEFT;
}

void PlayerObject::setStandRight()
{
	curCell = 0;
	width = 56;
	height = 63;
	picY = 0;
	picX = 0;
	endCell = 0;
	loopCells = false;
	startCell = 0;
	xspeed = 0;
	state = STANDRIGHT;
}

void PlayerObject::setStandLeft()
{
	curCell = 0;
	width = 56;
	height = 63;
	picY = 63;
	picX = 0;
	endCell = 0;
	loopCells = false;
	startCell = 0;
	xspeed = 0;
	state = STANDLEFT;
}

void PlayerObject::setJumpRight()
{
	curCell = 0;
	width = 56;
	height = 63;
	endCell = 1;
	loopCells = false;
	picY = 126;
	yspeed = -30;
	state = JUMPRIGHT;
	onground = false;
}

void PlayerObject::setJumpLeft()
{
	curCell = 0;
	width = 56;
	height = 63;
	endCell = 1;
	loopCells = false;
	picY = 189;
	yspeed = -30;
	state = JUMPLEFT;
	onground = false;
}

void PlayerObject::setShootRight()
{
	curCell = 0;
	width = 56;
	height = 63;
	picY = 126;
	endCell = 1;
	loopCells = false;
	startCell = 0;
	xspeed = 0;
	state = SHOOTRIGHT;
}

void PlayerObject::setShootLeft()
{
	curCell = 0;
	width = 56;
	height = 63;
	picY = 189;
	endCell = 0;
	loopCells = false;
	startCell = 0;
	xspeed = 0;
	state = SHOOTLEFT;
}

bool PlayerObject::isJumping()
{
	return (state == JUMPLEFT || state == JUMPRIGHT);
}

PlayerObject::~PlayerObject(void)
{
}
void PlayerObject::setStand(){
	if (state == JUMPLEFT && stoppedLeft == true)
	{
		setStandLeft();
	}
	else if (state == JUMPRIGHT && stoppedRight == true)
	{
		setStandRight();
	}
	else if (state == JUMPLEFT && stoppedLeft == false)
	{
		setMoveLeft();
	}
	else if (state == JUMPRIGHT && stoppedRight == false)
	{
		setMoveRight();
	}
}
