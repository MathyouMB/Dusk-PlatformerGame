#include "stdafx.h"
#include "Enemyobject.h"
//#include "JellyFishEnemy.h"
//#include "SeaHagEnemy.h"
#include "GreenRiderEnemy.h"


Enemyobject::Enemyobject(CString name, int x, int y) :WeaponsObject(name, x, y)
{
	alive = true;

}

void Enemyobject::move(){}
void Enemyobject::onhit(BulletObject * b){
	x += b->xspeed;
	enemyhealth -= b->damage;

}
Enemyobject::~Enemyobject()
{
}
