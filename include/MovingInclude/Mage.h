
#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include "Board.h"
#include "MovingInclude\Player.h"
using std::vector;


  

class Mage :public Player
{
public:
	using Player::Player;

	virtual void handleCollision(GameObjBase&) override;
	virtual void handleCollision(King&) override ;
	virtual void handleCollision(Warrior&) override;
	virtual void handleCollision(Thief&) override;
	virtual void handleCollision(Fire&) override;
	virtual void handleCollision(Fairy&) override ;
private:

};




