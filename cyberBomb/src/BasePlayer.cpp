#include "BasePlayer.h"

BasePlayer::BasePlayer()
{
    playerTexture.loadFromFile("rbombermanTux.png");
    playerSprite.setTexture(playerTexture);

}

sf::Sprite &BasePlayer::getPlayerSprite()
{
    return playerSprite;
}
sf::Texture &BasePlayer::getPlayerTexture()
{
    return playerTexture;
}

