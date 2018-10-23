#include "StdAfx.h"
#include "WeaponsObject.h"


WeaponsObject::WeaponsObject(CString filename, int xpos, int ypos) : GraphicsObject(filename, xpos, ypos)
{
}

void WeaponsObject::moveBullets()
{
	for (int i = 0; i < numBullets; i++)
	{
		if (bullets[i]->fired == true)
		{
			bullets[i]->move();
		}
	}
}


void WeaponsObject::drawBullets(HDC offScreenDC)
{
	for (int i = 0; i < numBullets; i++)
	{
		if (bullets[i]->fired == true)
		{
			bullets[i]->draw(offScreenDC);
		}
	}
}

void WeaponsObject::fireBullet(int x, int y, int xs, int ys)
{
	for (int i = 0; i < numBullets; i++)
	{
		if (bullets[i]->fired == false)
		{

			bullets[i]->x = x;
			bullets[i]->y = y;
			bullets[i]->xspeed = xs;
			bullets[i]->yspeed = ys;

			bullets[i]->fired = true;
			bullets[i]->distanceTravelled = 0;

			break;
		}
	}
}
void WeaponsObject::checkBulletBlock(GraphicsObject* block){
	for (int i = 0; i < numBullets; i++){
		if (bullets[i]->fired){
			if (bullets[i]->collide(block) && bullets[i]->exploding == false){
				if (abs(bullets[i]->x - block->x) < abs(bullets[i]->x - (block->x + block->width))){
					bullets[i]->x = block->x;
				}
				else if (abs(bullets[i]->x - block->x) > abs(bullets[i]->x - (block->x + block->width))){
					bullets[i]->x = block->x + block->width;
				}

				bullets[i]->setexplode(true);
			}

		}
	}

}

void WeaponsObject::checkPlayerBlock(GraphicsObject* block){

	if (this->collide(block)){
		if (prevX + width <= block->x){
			x = block->x - width;
		}
		else if (prevX >= block->x + block->width){
			x = block->x + block->width;
		}
		else if (prevY + height <= block->y){
			onground = true;
			y = block->y - height;
			yspeed = 0;
		}
		else if (prevY >= block->y + block->height){
			y = block->y + block->height + 1;
			yspeed = 0;
		}
	}
	else{
		onground = false;
	}
}




void WeaponsObject::checkBulletEntity(WeaponsObject* entity){
	for (int i = 0; i < numBullets; i++){
		if (bullets[i]->fired){
			if (bullets[i]->collide(entity) && bullets[i]->exploding == false){
				if (abs(bullets[i]->x - entity->x) < abs(bullets[i]->x - (entity->x + entity->width))){
					bullets[i]->x = entity->x;
				}
				else if (abs(bullets[i]->x - entity->x) > abs(bullets[i]->x - (entity->x + entity->width))){
					bullets[i]->x = entity->x + entity->width;
				}

				entity->onhit(bullets[i]);
				bullets[i]->setexplode(true);
			}

		}
	}

}




WeaponsObject::~WeaponsObject(void)
{
}
