#include "StaticInclude\Throne.h"

void Throne::handleCollision(GameObjBase& gameObject)
{
    if (&gameObject == this) return;
    // double dispatch
    gameObject.handleCollision(*this);
}
//--------------------------------------------------

void Throne::handleCollision(King& king)
{
    king.handleCollision(*this);
}
//--------------------------------------------------

void Throne::handleCollision(Warrior& warr)
{
    warr.backToPrevPos();
}
//--------------------------------------------------

void Throne::handleCollision(Mage& mage)
{
    mage.backToPrevPos();
}
//--------------------------------------------------

void Throne::handleCollision(Thief& thief)
{
    thief.backToPrevPos();
}
//--------------------------------------------------

void Throne::handleCollision(Fairy& fairy)
{
    fairy.backAndChangeDir();
}
