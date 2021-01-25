#pragma once
#include "Actor.h"

class Wall : public Actor
{
public:
	//Default Constructor for Wall with 0 arguments
	Wall();

	//Constructor that takes in 6 arguments
	Wall(float x, float y, float collisionRadius, char icon, float maxSpeed, int testVal);

	//Constructor that takes in 5 arguments
	Wall(float x, float y, float collisionRadius, char icon, float maxSpeed);
	
	//Override onCollision function for Wall that takes in an actor as an argument
	void onCollision(Actor* other) override;
	int testVariable;

	void start();
	void run();
	void update();
	void end();

	void draw() override;

};