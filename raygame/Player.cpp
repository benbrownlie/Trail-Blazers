#include "Player.h"

Player::Player()
{
	m_x = 0;
	m_y = 0;
	m_globalTransform = new MathLibrary::Matrix3();
	m_localTransform = new MathLibrary::Matrix3();
	m_rotation = new MathLibrary::Matrix3();
	m_translation = new MathLibrary::Matrix3();
	m_scale = new MathLibrary::Matrix3();

	setLocalPosition(MathLibrary::Vector2(m_x, m_y));
	m_velocity = MathLibrary::Vector2();
	m_collisionRadius = 2;
	m_icon = 'o';
	m_maxSpeed = 5;
}
Player::Player(float x, float y, float collision, char icon, float maxSpeed)
{
	m_x = x;
	m_y = y;
	m_globalTransform = new MathLibrary::Matrix3();
	m_localTransform = new MathLibrary::Matrix3();
	m_rotation = new MathLibrary::Matrix3();
	m_translation = new MathLibrary::Matrix3();
	m_scale = new MathLibrary::Matrix3();

	setLocalPosition(MathLibrary::Vector2(x, y));
	m_velocity = MathLibrary::Vector2();
	m_collisionRadius = collision;
	m_icon = icon;
	m_maxSpeed = maxSpeed;
}
void Player::update(float deltaTime)
{
	float xVelocity = 0;
	float yVelocity = 0;
	if (RAYLIB_H::IsKeyDown(KEY_A) == true)
	{
		xVelocity = -1;
	}
	else if (RAYLIB_H::IsKeyDown(KEY_D) == true)
	{
		xVelocity = 1;
	}
	else if (RAYLIB_H::IsKeyDown(KEY_W) == true)
	{
		yVelocity = 1;
	}
	else if (RAYLIB_H::IsKeyDown(KEY_S) == true)
	{
		yVelocity = -1;
	}
	setAcceleration(MathLibrary::Vector2(xVelocity, yVelocity));
}

void Player::draw()
{
	DrawCircle(getWorldPosition().x * 32, getWorldPosition().y * 32, 50, BLUE);
	//Draws the actor and a line indicating it facing to the raylib window
	DrawLine(
		(int)(getWorldPosition().x * 32),
		(int)(getWorldPosition().y * 32),
		(int)((getWorldPosition().x + getForward().x) * 32),
		(int)((getWorldPosition().y + getForward().y) * 32),
		WHITE
	);

	if (m_sprite)
		m_sprite->draw(*m_globalTransform);
	//Raylib.DrawCircleLines((int)(WorldPosition.X * 32), (int)(WorldPosition.Y * 32), _collisionRadius * 32, _rayColor);
}
//void Player::onCollision(Actor* other)
//{
//	
//	Game game;
//	Scene* scene = game.getScene(game.getCurrentSceneIndex());
//	if (other)
//	{
//		scene->removeActor();
//	}
//}

//void Player::addTrail()
//{
//	Game game;
//	Scene* scene = game.getScene(game.getCurrentSceneIndex());
//	scene.addActor(Trail);
//}
