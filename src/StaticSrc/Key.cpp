#include "StaticInclude\Key.h"

void Key::handleCollision(GameObjBase& gameObject)
{
	if (&gameObject == this) return;
	// double dispatch
	gameObject.handleCollision(*this);
}
//--------------------------------------------------

void Key::handleCollision(Thief& thief)
{
	thief.handleCollision(*this);
}


