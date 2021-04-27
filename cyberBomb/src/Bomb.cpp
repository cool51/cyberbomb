#include "Bomb.h"
#include"tempBlock.h"
#include"Player.h"
#include"Bomb.h"
#include"gameMusic.h"
#include"Map.h"
#include"texts.h"
#include<SFML/Graphics.hpp>
#include<iostream>
#include<windows.h>
using namespace std;


Bomb::Bomb()
{


    gameMusic music;
    flameCount=0;
    flameCount2=0;
    dtime=clk.restart();

    BombTexture.loadFromFile("bomb.png");
    flameTexture.loadFromFile("flameTexture3.png");
    flameSprite[0][0].setTexture(flameTexture);
    flameSprite[0][0].setTextureRect(sf::IntRect(flameCount,flameCount2,64,128));

    flameSprite[1][1].setTexture(flameTexture);
    flameSprite[1][1].setTextureRect(sf::IntRect(flameCount,flameCount2,64,128));

    flameSprite[2][2].setTexture(flameTexture);
    flameSprite[2][2].setTextureRect(sf::IntRect(flameCount,flameCount2,64,128));

    flameSprite[3][3].setTexture(flameTexture);
    flameSprite[3][3].setTextureRect(sf::IntRect(flameCount,flameCount2,64,128));

    flameSprite[4][4].setTexture(flameTexture);
    flameSprite[4][4].setTextureRect(sf::IntRect(flameCount,flameCount2,64,128));


    for(int i=0; i<5; i++)
    {



        flameSprite[i][i].setOrigin(32,96);
        flameSprite[i][i].scale(1.2,1.2);
        flameSprite[i][i].setPosition(3000,3000);
    }

    BombSprite.setTexture(BombTexture);
    BombSprite.setOrigin(32,32);
    BombSprite.setPosition(10000,6000);
    BombSprite.setScale(0.7,0.7);

}
void Bomb::  setBomb(sf::Vector2f playerPosition)
{




    BombSprite.setPosition(playerPosition.x,playerPosition.y);

    bool placed=true;

    dtime=clk.restart();


}

void Bomb::check(tempBlock &tBlock,Player &player,Player &player2,int &checkBomb,int &p1,int &p2 )
{
    if(placed=true)
    {
        checkBomb=1;
        dtime=clk.getElapsedTime();
        float second=dtime.asSeconds();


        sf::Vector2f tempPosition=BombSprite.getPosition();
        if(second>3.0)
        {





            for(int i=0; i<10; i++)
            {
                for(int j=0; j<10; j++)
                {

                    float dx=(BombSprite.getPosition().x)-(tBlock.tblockSprite[i][j].getPosition().x);
                    float  dy=(BombSprite.getPosition().y)-(tBlock.tblockSprite[i][j].getPosition().y);
                    if(abs(dx)<100&&abs(dy)<100)
                    {
                        tBlock.tblockSprite[i][j].setPosition(20000.f,2000.f);
                        flameSprite[i][i].setTextureRect(sf::IntRect(flameCount,flameCount2,64,128));








                    }


                }
            }


            {
                float dxP1=(BombSprite.getPosition().x)-(player.getPlayerSprite().getPosition().x);
                float  dyP1=(BombSprite.getPosition().y)-(player.getPlayerSprite().getPosition().y);
                float dxP2=(BombSprite.getPosition().x)-(player2.getPlayerSprite().getPosition().x);
                float dyP2=(BombSprite.getPosition().y)-(player2.getPlayerSprite().getPosition().y);

                if(abs(dxP1)<100&&abs(dyP1)<100)
                {


                    player.getPlayerSprite().setPosition(-100,-100);
                    p1--;




                }
                if(abs(dxP2)<100&&abs(dyP2)<100)
                {


                    player2.getPlayerSprite().setPosition(20000,20000);
                    p2--;


                }





            }


        }
//        if(second>3.0)
//
//        {
//            float dxP1=(BombSprite.getPosition().x)-(player.playerSprite.getPosition().x);
//            float  dyP1=(BombSprite.getPosition().y)-(player.playerSprite.getPosition().y);
//            float dxP2=(BombSprite.getPosition().x)-(player2.playerSprite.getPosition().x);
//            float dyP2=(BombSprite.getPosition().y)-(player2.playerSprite.getPosition().y);
//
//            if(abs(dxP1)<100&&abs(dyP1)<100)
//            {
//
//                player.playerSprite.setPosition(20000,20000);
//
//            }
//            if(abs(dxP2)<100&&abs(dyP2)<100)
//            {
//
//                player2.playerSprite.setPosition(20000,20000);
//
//            }
//
//
//
//
//
//        }

        if(second>2&&second<5)
        {

            flameSprite[0][0].setTextureRect(sf::IntRect(flameCount,flameCount2,64,128));
            flameSprite[0][0].setPosition(tempPosition.x,tempPosition.y);
            flameSprite[1][1].setTextureRect(sf::IntRect(flameCount,flameCount2,64,128));
            flameSprite[1][1].setPosition(tempPosition.x+40,tempPosition.y);
            flameSprite[2][2].setTextureRect(sf::IntRect(flameCount,flameCount2,64,128));
            flameSprite[2][2].setPosition(tempPosition.x-40,tempPosition.y);
            flameSprite[3][3].setTextureRect(sf::IntRect(flameCount,flameCount2,64,128));
            flameSprite[3][3].setPosition(tempPosition.x,tempPosition.y+40);
            flameSprite[4][4].setTextureRect(sf::IntRect(flameCount,flameCount2,64,128));
            flameSprite[4][4].setPosition(tempPosition.x,tempPosition.y-40);


            for(int i=0; i<5; i++)
            {



                if ((flameSprite[i][i].getPosition().y>80.0f)&&(flameSprite[i][i].getPosition().x<1040.0f)&&flameSprite[i][i].getPosition().y<755.0f&&  (flameSprite[i][i].getPosition().x>385.0f))
                {

                    music.playBomb();
                    Sleep(15);
                    music.pauseBomb();

                }


            }







            if(flameCount<512)
            {

                flameCount+=64;
            }

            else
                flameCount=0;
            if(flameCount2<512)
            {
                flameCount2+=128;
            }


            else
                flameCount2=0;
        }


        dtime=clk.getElapsedTime();
        float sec=dtime.asSeconds();
        if(sec>4.0)
        {
            BombSprite.setPosition(4000.f,2000.f);

            placed=false;
            checkBomb=0;

        }

    }
}
void Bomb::DrawFlame(sf::RenderWindow &flameDisplay)
{
    for(int i=0; i<5; i++)
    {

        flameDisplay.draw(flameSprite[i][i]);






    }
}

sf::Sprite &Bomb::getBombSprite()
{
    return BombSprite;
}






