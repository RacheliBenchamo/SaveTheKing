
#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include "Board.h"
#include "MovingInclude\Player.h"
using std::vector;




class Warrior :public Player
{
public:
	using Player::Player;

	virtual void handleCollision(GameObjBase&) override;
	virtual void handleCollision(King&) override ;
	virtual void handleCollision(Mage&) override;
	virtual void handleCollision(Thief&) override;
	virtual void handleCollision(Ork&) override;
	virtual void handleCollision(Teleport&) override ;
	virtual void handleCollision(Fairy&) override ;
protected:

};




