#include "MovingInclude\Thief.h"


//------------------------------------------

void Thief::handleCollision(GameObjBase& gameObject)
{
    if (&gameObject == this) return;
    // double dispatch
    gameObject.handleCollision(*this);
}
//------------------------------------------

void Thief::handleCollision(King& king)
{
    king.backToPrevPos();
}
//------------------------------------------

void Thief::handleCollision(Warrior& warrior)
{
    warrior.backToPrevPos();
}
//------------------------------------------

void Thief::handleCollision(Mage& mage)
{
    mage.backToPrevPos();
}
//------------------------------------------

void Thief::handleCollision(Gate& gate)
{
    if (m_haveKey)
    {
        static sf::Sound effect;
        effect.setBuffer(*FileManager::p2FileManager().getSound(S_OPEN_GATE));
        effect.play();
        effect.setVolume(VOLUME_COLLISION);

        m_haveKey = false;
        gate.setDelete();
        sf::Sprite sprite = getSprite();
        sprite.setTexture(*(FileManager::p2FileManager().getIconTexture(THIEF)));
        setSprite(sprite);
    }
    else
        backToPrevPos();


}
//------------------------------------------
void Thief::handleCollision(Teleport& teleport)
{
    teleport.handleCollision(*this);
}
//------------------------------------------

void Thief::handleCollision(Key& key)
{
    if (!m_haveKey)
    {
        static sf::Sound effect;
        effect.setBuffer(*FileManager::p2FileManager().getSound(S_TAKE_KEY));
        effect.play();
        effect.setVolume(VOLUME_COLLISION);

        m_haveKey = true;
        key.setDelete();
        sf::Sprite sprite = getSprite();
        sprite.setTexture(*(FileManager::p2FileManager().getIconTexture(THIEF_WITH_KEY)));
        setSprite(sprite);
    }

}
//------------------------------------------

void Thief::handleCollision(Fairy& fairy)
{
    fairy.startSound();
    backToPrevPos();
    fairy.backAndChangeDir();

}

