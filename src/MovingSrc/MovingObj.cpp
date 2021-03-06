#include "MovingInclude\\MovingObj.h"
#include "Macros.h"

//-------------------------------------------
//constructor

MovingObj::MovingObj(icons icon, int i, int j)
	 :GameObjBase(icon, i, j),
	m_animationCol(0), m_animationRow(0)
{
	sf::Sprite sprite = getSprite();
	m_prevPos = sprite.getPosition();
	sprite.setTextureRect(sf::IntRect(32,0, 32, 29));
	sprite.setScale(1.8, 1.8);
	setSprite(sprite);
}
//------------------------------------------
//set the sprite pos to her prev pos

void MovingObj::backToPrevPos()
{
	setPos(m_prevPos);
}
//------------------------------------------
//return true if the sprite pos is out od the window
//else,return false

bool MovingObj::outWindow(sf::Vector2f pos, sf::Vector2f levelSize) const
{
	if (pos.x < ((MAX_WIDTH -levelSize.y) / 2) || pos.y < ((MAX_HEIGHT -levelSize.x) / 2) ||
		pos.y >= (levelSize.x+((MAX_HEIGHT - levelSize.x) / 2) - 1)* P_SIZE ||
		pos.x >= (levelSize.y + ((MAX_WIDTH -levelSize.y) / 2) - 1) * P_SIZE)
			return true;
	
	    return false;
}
//------------------------------------------
//update the animation of the charcter by 
//the direction it goes to

void MovingObj::updateAnimation()
{
	if (m_currDirection == DVec[DOWN])
	{
		m_animationRow = 0;
		updateSpriteCol();
	}
	else if (m_currDirection == DVec[LEFT])
	{
		m_animationRow = 1;
		updateSpriteCol();
	}
	else if (m_currDirection == DVec[RIGHT])
	{
		m_animationRow = 2;
		updateSpriteCol();
	}
	else if (m_currDirection == DVec[UP])
	{
		m_animationRow = 3;
		updateSpriteCol();
	}
}
//------------------------------------------------------------
//update the col in the sprite pic to create run affect

void MovingObj::updateSpriteCol()
{
	sf::Sprite sprite = getSprite();

	if (m_animationCol == 2)
		m_animationCol = 0;
	else
		m_animationCol++;

	sprite.setTextureRect(sf::IntRect(m_animationCol * 32, m_animationRow * 32, 32, 32));
	setSprite(sprite);
}
//------------------------------------------
//return the right direction by which key pressed

sf::Vector2f MovingObj::getDirection() const
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return { 1, 0 };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		return { -1, 0 };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		return { 0, -1 };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return { 0, 1 };

	return { 0, 0 };
}