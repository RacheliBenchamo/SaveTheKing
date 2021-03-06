
#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include "Board.h"
#include "StaticObj.h"


using std::vector;


class Fire :public StaticObj
{
public:
	using StaticObj::StaticObj;

	virtual void startSound()override ;

	virtual void handleCollision(GameObjBase&) override;
	virtual void handleCollision(King&) override;
	virtual void handleCollision(Warrior&) override;
	virtual void handleCollision(Mage&) override;
	virtual void handleCollision(Thief&) override;
	virtual	void handleCollision(Fairy&) override;

private:

};




