#include "Game.h"

Player::Player()
{
	m_x = 0;
	m_y = 0;
	m_collisionRadius = 2;
	m_icon = 'o';
	m_maxSpeed = 5;
}
Player::Player(float x, float y, float collision, char icon, float maxSpeed)
{
	m_x = x;
	m_y = y;
	m_collisionRadius = collision;
	m_icon = icon;
	m_maxSpeed = maxSpeed;
}

void Player::onCollision(Actor* other)
{
	
	//Game game;
	//Scene* scene = game.getScene(game.getCurrentSceneIndex());
	//if (checkCollision(other) == true)
	//{
	//	scene->removeActor(m_player1);
	//}
}

//void Player::addTrail()
//{
//	Game game;
//	Scene* scene = game.getScene(game.getCurrentSceneIndex());
//	scene.addActor(Trail);
//}