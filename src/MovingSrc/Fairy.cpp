#include "MovingInclude/Fairy.h"
#include "MovingInclude/King.h"

//--------------------------------------------------
//constructor
Fairy::Fairy(icons icon, int i, int j)
	: MovingObj(icon, i, j)
{
	setFairyDirection();
}
//--------------------------------------------------
//handle fairy moving

void Fairy::move(sf::Time& deltaTime, sf::Vector2f levelSize)
{
	updateAnimation();
	sf::Sprite sprite = getSprite();
	setPrevPos(sprite.getPosition());
	sprite.move(getCurrDir() * FAIRY_SPEED * deltaTime.asSeconds());
	setSprite(sprite);

	//check bounds
	if (outWindow(sprite.getPosition(), levelSize))
		handleFairyOutWindow();
}
//--------------------------------------------------
//start touch fairy sound

void Fairy::startSound()
{
	static sf::Sound effect;
	effect.setBuffer(*FileManager::p2FileManager().getSound(S_TOUCH_FAIRY));
	effect.play();
	effect.setVolume(VOLUME_COLLISION);
}
//----------------------------------------------------

void Fairy::handleFairyOutWindow()
{
	backToPrevPos();
	//chage direction
	setFairyDirection();
}

//----------------------------------------------------

sf::Vector2f Fairy::grillDirection() const
{
	int dir = rand() % 4;

	switch ((direction)dir)
	{
	case RIGHT:
		return  { 1, 0 };
	case LEFT:
		return { -1, 0 };
	case UP:
		return  { 0, -1 };
	case DOWN:
		return { 0, 1 };
	}
	return { 0, 0 };
}
//--------------------------------------------------

void Fairy::setFairyDirection()
{
	setCurrDir(grillDirection());
}
//--------------------------------------------------

void Fairy::handleCollision(GameObjBase& gameObject)
{
	if (&gameObject == this) return;
	// double dispatch
	gameObject.handleCollision(*this);
}
//--------------------------------------------------

void Fairy::backAndChangeDir()
{
	backToPrevPos();
	setFairyDirection();
}




