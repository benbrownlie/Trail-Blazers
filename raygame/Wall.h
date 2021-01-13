#pragma once
#include "Actor.h"
#include "Game.h"

class Wall : public Actor
{
public:
	Wall(float x, float y, float collisionRadius, char icon, float maxSpeed) : Actor(x, y, collisionRadius, icon, maxSpeed) {}

	 void onCollision(Actor* Other) override;

};