#include "player.h"
#include "graphics.h"

namespace player_constants
{
	const float WALK_SPEED = 0.2f;
	const float GRAVITY = 0.98f;
}

Player::Player()
{
}

Player::Player(Graphics &graphics, float x, float y) :
	AnimatedSprite(graphics, "Imagenes/Sprites/geruzon.png", 0, 0, 48, 48, x, y, 100)
{ 
	graphics.loadImage("Imagenes/Sprites/geruzon.png");
	this->setupAnimations();
	this->playAnimation("Idle");
}

void Player::setupAnimations()
{
	this->addAnimation(5, 0, 142, "RunLeft", 48, 48, Vector2(0, 0));
	this->addAnimation(5, 0, 0, "RunRight", 48, 48, Vector2(0, 0));
	this->addAnimation(2, 0, 63, "Idle", 48, 48, Vector2(0, 0));
}

void Player::animationDone(std::string currentAnimation)
{
	
}

void Player::moveLeft()
{
	this->_dx = -player_constants::WALK_SPEED;
	this->playAnimation("RunLeft");
	this->_facing = LEFT;

}

void Player::moveRight()
{
	this->_dx = player_constants::WALK_SPEED;
	this->playAnimation("RunRight");
	this->_facing = RIGHT;
}

void Player::stopMoving()
{
	this->_dx = 0;
	this->playAnimation(this->_facing == RIGHT ? "Idle" : "Idle");
}

void Player::update(float elapsedTime)
{
	//Move by dx
	this->_x += this->_dx * elapsedTime;
	AnimatedSprite::update(elapsedTime);	
}

void Player::draw(Graphics &graphics)
{
	AnimatedSprite::draw(graphics, this->_x, this->_y);
}