#include "tempBlock.h"
#include<SFML/Graphics.hpp>

tempBlock::tempBlock()
{
    tblockTexture.loadFromFile("temporaryBlock.png");
    portalTexture.loadFromFile("portal.png");



    float tx=523.0f,ty=224.0f;
    for (int i = 0; i<4 ; i++)
    {
        for (int j = 0; j<4; j++)
        {

            if (i==3 && j==0)
            {
                ty +=128.0f;
                continue;

            }
            tblockSprite[i][j].setTexture(tblockTexture);
            tblockSprite[i][j].setPosition(tx,ty);
            tblockSprite[i][j].setOrigin(32.0f,32.0f);


            ty += 128.0f;
        }
        tx += 128.0f;
        ty = 224.0f;
    }


    tblockSprite[5][1].setTexture(tblockTexture);
    tblockSprite[5][1].setPosition(651.0f,736.0f);
    tblockSprite[5][1].setOrigin(32.0f,32.0f);

    tblockSprite[5][2].setTexture(tblockTexture);
    tblockSprite[5][2].setPosition(715.0f,736.0f);
    tblockSprite[5][2].setOrigin(32.0f,32.0f);

    tblockSprite[5][3].setTexture(tblockTexture);
    tblockSprite[5][3].setPosition(779.0f,736.0f);



    tblockSprite[5][3].setOrigin(32.0f,32.0f);

    tblockSprite[5][4].setTexture(tblockTexture);
    tblockSprite[5][4].setPosition(779.0f,416.0f);
    tblockSprite[5][4].setOrigin(32.0f,32.0f);

    tblockSprite[5][5].setTexture(tblockTexture);
    tblockSprite[5][5].setPosition(715.0f,480.0f);
    tblockSprite[5][5].setOrigin(32.0f,32.0f);

    tblockSprite[6][1].setTexture(tblockTexture);
    tblockSprite[6][1].setPosition(651.0f,416.0f);
    tblockSprite[6][1].setOrigin(32.0f,32.0f);

    tblockSprite[6][2].setTexture(tblockTexture);
    tblockSprite[6][2].setPosition(1035.0f,480.0f);
    tblockSprite[6][2].setOrigin(32.0f,32.0f);

    tblockSprite[6][3].setTexture(tblockTexture);
    tblockSprite[6][3].setPosition(1035.0f,96.0f);
    tblockSprite[6][3].setOrigin(32.0f,32.0f);

    tblockSprite[6][4].setTexture(tblockTexture);
    tblockSprite[6][4].setPosition(971.0f,96.0f);
    tblockSprite[6][4].setOrigin(32.0f,32.0f);

    tblockSprite[6][5].setTexture(tblockTexture);
    tblockSprite[6][5].setPosition(1035.0f,160.0f);
    tblockSprite[6][5].setOrigin(32.0f,32.0f);
}


void tempBlock::DrawtblockSprite(sf::RenderWindow &tdisplay)
{
    portalSprite[0].setTexture(portalTexture);
    portalSprite[0].setTextureRect(sf::IntRect(portalCountLoop,0,64,64));
    portalSprite[0].setOrigin(32.0f,32.0f);
    portalSprite[0].setPosition(843.0f,224.0f);

    portalSprite[1].setTexture(portalTexture);
    portalSprite[1].setTextureRect(sf::IntRect(portalCountLoop,0,64,64));
    portalSprite[1].setOrigin(32.0f,32.0f);
    portalSprite[1].setPosition(459.0f,480.0f);


    tdisplay.draw(portalSprite[0]);
    tdisplay.draw(portalSprite[1]);

    for(int i=0; i<7; i++)
    {
        for(int j=0; j<7; j++)
        {



            tdisplay.draw(tblockSprite[i][j]);

        }


    }

    portalCountLoop+=64;
    if(portalCountLoop>256)
    {
        portalCountLoop=0;
    }

}








