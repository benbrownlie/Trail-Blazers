#pragma once
#include "Game.h"

class Player : Actor
{
public:
	Player();
	Player(float x, float y, float collisionRadius, char icon, float maxSpeed);
	void onCollision(Actor* other);
	void addTrail(Actor actor);
private:
	float m_x;
	float m_y;
	float m_collisionRadius;
	char m_icon;
	float m_maxSpeed;
};