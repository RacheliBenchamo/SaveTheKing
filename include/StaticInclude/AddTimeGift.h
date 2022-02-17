#pragma once
#include "StaticInclude\Gift.h"

class AddTimeGift : public Gift
{
public:
	using Gift::Gift;
	~AddTimeGift() {};

	virtual void handleCollision(King&) override { setDelete(); startSound();}
	virtual void handleCollision(Warrior&) override { setDelete(); startSound();}
	virtual void handleCollision(Mage&) override { setDelete(); startSound();}
	virtual void handleCollision(Thief&) override { setDelete(); startSound();}

};
