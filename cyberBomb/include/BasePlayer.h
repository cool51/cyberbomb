#ifndef BASEPLAYER_H
#define BASEPLAYER_H
#include<iostream>
#include "SFML/Graphics.hpp"
#include<Perblock.h>
#include<tempBlock.h>

class BasePlayer
{
public:

    BasePlayer();
    sf::Sprite &getPlayerSprite();
    sf::Texture &getPlayerTexture();
    virtual   void wallCollisionDetection()=0;
    virtual void permanentBlockCollisionDetection(Perblock permanentBlock,char keyEntered)=0;
    virtual void temporaryBlockCollisionDetection(tempBlock temporaryBlock,char keyEnt)=0;
    virtual void enemyCollisionDetection(sf::Sprite &,sf::Sprite &,float,float)=0;

protected:


    sf::Sprite playerSprite;


private:
    sf::Texture playerTexture;

};

#endif // BASEPLAYER_H
