#ifndef TEMPBLOCK_H
#define TEMPBLOCK_H
#include<SFML/Graphics.hpp>

class tempBlock
{
private:
    int tblock_x,tblock_y;
    sf::Texture tblockTexture;
    sf::Texture portalTexture;
    sf::Vector2u tblockSize;





    public:
        tempBlock();
          sf::  Sprite tblockSprite[7][7];
          sf::Sprite portalSprite[2];
        sf::Vector2u gettblockSize();
            int portalCountLoop=0;
        void DrawtblockSprite(sf::RenderWindow& tdisplay);

};

#endif // TEMPBLOCK_H
