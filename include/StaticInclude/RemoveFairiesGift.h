#pragma once
#include "Gift.h"

class RemoveFairiesGift : public Gift
{
public:
	using Gift::Gift;
	~RemoveFairiesGift() {};

	virtual void handleCollision(GameObjBase&) override {};
	virtual void handleCollision(King&) override { setDelete(); startSound();}
	virtual void handleCollision(Warrior&) override { setDelete(); startSound();}
	virtual void handleCollision(Mage&) override { setDelete(); startSound();}
	virtual void handleCollision(Thief&) override { setDelete(); startSound();}

};
