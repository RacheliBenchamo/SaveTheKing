#include "StaticInclude\Fire.h"

//--------------------------------------------------
//start touch fire sound

void Fire::startSound()
{
    static sf::Sound effect;
    effect.setBuffer(*FileManager::p2FileManager().getSound(S_TOUCH_FIRE));
    effect.play();
    effect.setVolume(VOLUME_COLLISION);
}
//--------------------------------------------------

void Fire::handleCollision(GameObjBase& gameObject)
{
    if (&gameObject == this) return;
    // double dispatch
    gameObject.handleCollision(*this);
}
//--------------------------------------------------

void Fire::handleCollision(King& king)
{
    startSound();
    king.backToPrevPos();
}
//--------------------------------------------------

void Fire::handleCollision(Mage& mage)
{
    mage.handleCollision(*this);
}
//--------------------------------------------------

void Fire::handleCollision(Thief& thief)
{
    startSound();
    thief.backToPrevPos();
}
//--------------------------------------------------

void Fire::handleCollision(Warrior& warrior)
{
    startSound();
    warrior.backToPrevPos();
}
//--------------------------------------------------

void Fire::handleCollision(Fairy& fairy)
{
    fairy.backAndChangeDir();
}
