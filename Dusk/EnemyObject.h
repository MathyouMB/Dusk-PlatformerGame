#pragma once
#include "WeaponsObject.h"
class Enemyobject : public WeaponsObject
{
public:
	Enemyobject(CString name, int x, int y);
	~Enemyobject();
	void onhit(BulletObject*);
	virtual void move();
	bool alive;
	int enemyhealth;
};

