
#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include "Board.h"
#include "MovingInclude\Player.h"
#include "GameObjBase.h"
using std::vector;



class King :public Player
{
public:
	using Player::Player;

	bool ReachedTheThrone() { return m_ReachedTheThrone; };
	void resetReachedTheThrone() { m_ReachedTheThrone=false; };

	virtual void handleCollision(GameObjBase&) override ;
	virtual void handleCollision(Warrior&) override ;
	virtual void handleCollision(Mage&) override ;
	virtual void handleCollision(Thief&) override ;
	virtual void handleCollision(Teleport&) override;
	virtual void handleCollision(Throne&) override ;
	virtual void handleCollision(Fairy&) override;
	
private:
	bool m_ReachedTheThrone = false;
};
