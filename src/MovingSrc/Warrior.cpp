#include "MovingInclude\Warrior.h"


//----------------------------------------------------

void Warrior::handleCollision(GameObjBase& gameObject)
{
    if (&gameObject == this) return;
    // double dispatch
    gameObject.handleCollision(*this);
}
//------------------------------------------

void Warrior::handleCollision(King& king)
{
    king.backToPrevPos();
}
//------------------------------------------

void Warrior::handleCollision(Mage& mage)
{
    mage.backToPrevPos();
}
//------------------------------------------

void Warrior::handleCollision(Thief& thief)
{
    thief.backToPrevPos();
}
//------------------------------------------]

void Warrior::handleCollision(Ork& ork)
{
    static sf::Sound effect;
    effect.setBuffer(*FileManager::p2FileManager().getSound(S_KILL_ORK));
    effect.play();
    effect.setVolume(VOLUME_COLLISION);

    ork.setReplace();
}
//------------------------------------------
void Warrior::handleCollision(Teleport& teleport)
{
    teleport.handleCollision(*this);
}
//------------------------------------------

void Warrior::handleCollision(Fairy& fairy)
{
    fairy.startSound();
    backToPrevPos();
    fairy.backAndChangeDir();
}
//------------------------------------------
