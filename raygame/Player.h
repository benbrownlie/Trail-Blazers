#pragma once
#include<cmath>
#include "Actor.h"
#include "raylib.h"
#include "Sprite.h"

class Sprite;

class Player : public Actor
{
public:
	Player();
	Player(float x, float y, float collisionRadius, char icon, float maxSpeed);
	Player(float x, float y, float collisionRadius, Sprite* sprite, float maxSpeed = 1) : Actor(x, y, collisionRadius, ' ', maxSpeed) { m_sprite = sprite; };
	Player(float x, float y, float collisionRadius, const char* spriteFilePath, float maxSpeed = 1) : Actor(x, y, collisionRadius, ' ', maxSpeed) { m_sprite = new Sprite(spriteFilePath); };
	virtual void update(float deltatime) override;
	virtual void draw();
	//void onCollision(Actor* other);
	//void addTrail(Actor actor);
private:
	float m_x;
	float m_y;
	float m_collisionRadius;
	char m_icon;
	float m_maxSpeed;
	Sprite* m_sprite;
};