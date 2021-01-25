#include "Wall.h"
#include "raylib.h"
#include "Game.h"
Wall::Wall()
{

}

Wall::Wall(float x, float y, float collisionRadius, char icon, float maxSpeed, int testVal) : Actor(x, y, collisionRadius, icon, maxSpeed)
{
	testVariable = testVal;
}

Wall::Wall(float x, float y, float collisionRadius, char icon, float maxSpeed) : Actor(x, y, collisionRadius, icon, maxSpeed)
{

}

void Wall::onCollision(Actor* other)
{
	Game::destroy(other);
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

void Wall::draw()
{
	RAYLIB_H::DrawText(&m_icon, getWorldPosition().x * 32, getWorldPosition().y * 32, 50, BLUE);
}