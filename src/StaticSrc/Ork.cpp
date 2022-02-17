#include "StaticInclude\ork.h"


//--------------------------------------------------
//start touch ork sound

void Ork::startSound()
{
    static sf::Sound effect;
    effect.setBuffer(*FileManager::p2FileManager().getSound(S_TOUCH_ORK));
    effect.play();
    effect.setVolume(VOLUME_COLLISION);
}
//--------------------------------------------------

void Ork::handleCollision(GameObjBase& gameObject)
{
    if (&gameObject == this) return;
    // double dispatch
    gameObject.handleCollision(*this);
}
//--------------------------------------------------

void Ork::handleCollision(King& king)
{
    startSound();
    king.backToPrevPos();
}
//--------------------------------------------------

void Ork::handleCollision(Warrior& warr)
{
    warr.handleCollision(*this);
}
//--------------------------------------------------

void Ork::handleCollision(Mage& mage)
{
    startSound();
    mage.backToPrevPos();
}
//--------------------------------------------------

void Ork::handleCollision(Thief& thief)
{
    startSound();
    thief.backToPrevPos();
}
//--------------------------------------------------

void Ork::handleCollision(Fairy& fairy)
{
    fairy.backAndChangeDir();
}

