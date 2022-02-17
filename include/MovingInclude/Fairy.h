#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Board.h"
#include "MovingInclude\MovingObj.h"
#include "GameObjBase.h"

using std::vector;


class Fairy :public MovingObj
{
public:
	Fairy(icons, int, int);
	virtual void move(sf::Time&, sf::Vector2f) override;
	void setFairyDirection();
	void backAndChangeDir();
    void startSound();

	virtual void handleCollision(GameObjBase&) override;
	virtual void handleCollision(Fairy&) override { backAndChangeDir(); }

private:
	sf::Vector2f grillDirection()const;

	void handleFairyOutWindow();
	int firstTime = 100;
	int numOfTimes = 0;
};




