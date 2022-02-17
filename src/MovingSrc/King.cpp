#include "MovingInclude\King.h"
#include "MovingInclude\Fairy.h"

//------------------------------------------

void King::handleCollision(GameObjBase& gameObject)
{
    if (&gameObject == this) return;
    // double dispatch
    gameObject.handleCollision(*this);
}
//------------------------------------------

void King::handleCollision(Warrior& warrior)
{
    warrior.backToPrevPos();
   
}
//------------------------------------------

void King::handleCollision(Mage& mage)
{
    mage.backToPrevPos();
   
}
//------------------------------------------

void King::handleCollision(Thief& thief)
{
    thief.backToPrevPos();
}
//------------------------------------------

void King::handleCollision(Throne&)
{
    m_ReachedTheThrone = true;
}
//------------------------------------------
void King::handleCollision(Teleport& teleport)
{
    teleport.handleCollision(*this);
}
//------------------------------------------

void King::handleCollision(Fairy& fairy)
{
    fairy.startSound();
    backToPrevPos();
    fairy.backAndChangeDir();
}
