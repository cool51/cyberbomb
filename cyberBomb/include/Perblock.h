#ifndef PERBLOCK_H
#define PERBLOCK_H
#include<SFML/Graphics.hpp>



class Perblock
{
private:
    int pblock_x,pblock_y;
    sf::Texture pblockTexture;
    sf::Vector2u pblockSize;
public:
    Perblock();
    sf::  Sprite pblockSprite[7][7];
    sf::Vector2u getPblockSize();
    void DrawPblockSprite(sf::RenderWindow& Displayz);



};

#endif // PERBLOCK_H
