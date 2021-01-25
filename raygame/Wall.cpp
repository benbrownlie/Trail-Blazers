#include "Wall.h"
Wall::Wall()
{

}

Wall::Wall(float x, float y, float collisionRadius, char icon, float maxSpeed, int testVal) : Actor(x, y, collisionRadius, icon, maxSpeed)
{
	testVariable = testVal;
}

Wall::Wall(float x, float y, float collisionRadius, char icon, float maxSpeed)
{

}

void Wall::onCollision(Actor* other)
{
	//temporary bool until a different collision method is written
	tempBool = false;
}

void Wall::start()
{

}

void Wall::run()
{

}

void Wall::update()
{

}

void Wall::end()
{

}
