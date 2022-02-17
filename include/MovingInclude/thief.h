
#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include "Board.h"
#include "Player.h"
using std::vector;




class Thief :public Player
{
public:
	using Player::Player;

	virtual void handleCollision(GameObjBase&) override;
	virtual void handleCollision(King&) override ;
	virtual void handleCollision(Warrior&) override;
	virtual void handleCollision(Mage&) override;
	virtual void handleCollision(Gate&) override ;
	virtual void handleCollision(Teleport&) override ;
	virtual	void handleCollision(Key& ) override;
	virtual void handleCollision(Fairy&) override;

private:
	bool m_haveKey = false;
	
};




