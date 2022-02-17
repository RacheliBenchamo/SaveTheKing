#include "MovingInclude\Mage.h"

//------------------------------------------

void Mage::handleCollision(GameObjBase& gameObject)
{
    if (&gameObject == this) return;
    // double dispatch
    gameObject.handleCollision(*this);
}
//------------------------------------------
void Mage::handleCollision(King& king)
{
    king.backToPrevPos();
}

//------------------------------------------
void Mage::handleCollision(Warrior& warrior)
{
    warrior.backToPrevPos();
}
//------------------------------------------
void Mage::handleCollision(Thief& thief)
{
    thief.backToPrevPos();
}
//------------------------------------------
void Mage::handleCollision(Fire& fire)
{
    static sf::Sound effect;
    effect.setBuffer(*FileManager::p2FileManager().getSound(S_TURN_OFF_FIRE));
    effect.play();
    effect.setVolume(VOLUME_COLLISION);
    fire.setDelete();
}
//------------------------------------------
void Mage::handleCollision(Fairy& fairy)
{
    fairy.startSound();
    backToPrevPos();
    fairy.backAndChangeDir();
}

