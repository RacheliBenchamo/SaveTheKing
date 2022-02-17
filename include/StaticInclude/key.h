
#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include "Board.h"
#include "StaticObj.h"


using std::vector;


class Key :public StaticObj
{
public:
	using StaticObj::StaticObj;

	virtual void startSound()override {};

	virtual void handleCollision(GameObjBase&) override;
	virtual void handleCollision(Thief&) override;
private:

};




