#include "Player.h"
#include "Game.h"

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
	float x = -Game::getKeyDown(KEY_A) + Game::getKeyDown(KEY_D);
	float y = -Game::getKeyDown(KEY_W) + Game::getKeyDown(KEY_S);
	setAcceleration(MathLibrary::Vector2(x, y));
	if (getVelocity().getMagnitude() > 0)
	{
		lookAt(getWorldPosition() + getVelocity().getNormalized());
	}
	
	*m_localTransform = *m_translation * *m_rotation * *m_scale;

	*m_globalTransform = *m_localTransform;

	setVelocity(m_velocity + m_acceleration);
	
	if (m_velocity.getMagnitude() > m_maxSpeed)
		m_velocity = m_velocity.getNormalized() * m_maxSpeed;

	//Increase position by the current velocity
	setLocalPosition(getLocalPosition() + m_velocity * deltaTime);
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
}
bool Player::checkCollision(Player* other)
{
	float distance = (other->getWorldPosition() - getWorldPosition()).getMagnitude();
	return distance <= m_collisionRadius + other->m_collisionRadius;
}

void Player::onCollision(Actor* other)
{
	Game::destroy(this);
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
