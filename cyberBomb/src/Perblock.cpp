#include "Perblock.h"
#include <SFML/Graphics.hpp>
Perblock::Perblock()
{


    pblockTexture.loadFromFile("permanentBlock.png");
    float px = 459.0f, py = 160.0f;
    for (int i = 0; i<5 ; i++)
    {
        for (int j = 0; j<5; j++)
        {
if(i!=3||j!=0)
{


            pblockSprite[i][j].setTexture(pblockTexture);
            pblockSprite[i][j].setPosition(px,py);
            pblockSprite[i][j].setOrigin(32.0f,32.0f);
}

            py += 128.0f;
        }
        px += 128.0f;
        py = 160.0f;
    }
    pblockSprite[5][1].setTexture(pblockTexture);
    pblockSprite[5][1].setPosition(715.0f,352.0f);
    pblockSprite[5][1].setOrigin(32.0f,32.0f);

    pblockSprite[5][2].setTexture(pblockTexture);
    pblockSprite[5][2].setPosition(587.0f,96.0f);
    pblockSprite[5][2].setOrigin(32.0f,32.0f);



    pblockSprite[5][3].setTexture(pblockTexture);
    pblockSprite[5][3].setPosition(715.0f,96.0f);
    pblockSprite[5][3].setOrigin(32.0f,32.0f);

    pblockSprite[5][4].setTexture(pblockTexture);
    pblockSprite[5][4].setPosition(779.0f,544.0f);
    pblockSprite[5][4].setOrigin(32.0f,32.0f);

    pblockSprite[5][5].setTexture(pblockTexture);
    pblockSprite[5][5].setPosition(715.0f,288.0f);
    pblockSprite[5][5].setOrigin(32.0f,32.0f);
}
sf::Vector2u Perblock::getPblockSize()
{
    pblockSize=pblockTexture.getSize();
    return pblockSize;
}
void Perblock::DrawPblockSprite(sf::RenderWindow &Display)
{
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            Display.draw(pblockSprite[i][j]);

        }
    }



}


