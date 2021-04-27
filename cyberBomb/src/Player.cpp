#include "Player.h"
#include"Perblock.h"
#include"tempBlock.h"
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;

Player::Player(float x,float y,sf::Color rang,float lifeX,float lifeY)
{
    lifeCount=4;



    ///  playerSpeed=100;
// playerTexture.loadFromFile("rbombermanTux.png");
    //playerSprite.setTexture(playerTexture);
    playerSprite.setTextureRect(sf::IntRect(0,0,48,96));
    playerSprite.setOrigin(24,85);
    playerSprite.setPosition(x,y);
    playerSprite.setScale(0.6,0.6);
    playerSprite.setColor(rang);
    lifeSprite[0].setTexture( getPlayerTexture());
    lifeSprite[0].setTextureRect(sf::IntRect(0,0,192,96));
    lifeSprite[0].setOrigin(0.0f,0.0f);
    lifeSprite[0].setScale(0.6,0.6);
    lifeSprite[0].setPosition(lifeX,lifeY);

    lifeSprite[0].setColor(rang);
    playerSprite.setColor(rang);

    playerSpeed=10.0f;
    countWidthRight=0;
    countWidthLeft=0;


}

void Player::moveRight()
{
    if(stopRight==false)


    {


        if(countWidthRight>=336)
        {
            countWidthRight=0;
        }
        else
            countWidthRight+=48;

        playerSprite.move(playerSpeed,0.0f);
        playerSprite.setTextureRect(sf::IntRect(countWidthRight,0,48,96));

        playerSprite.getPosition();

        stopLeft=false;
        stopDown=false;
        stopUp=false;
    }
    else
    {
        playerSprite.move(0.0f,0.0f);
        stopLeft=false;
        stopDown=false;
        stopUp=false;

    }
    /// pressedRight=true;

}

void Player::moveDown()
{
    if(stopDown==false)

    {
        if(countWidthRight>=336)
        {
            countWidthRight=0;
        }
        else
            countWidthRight+=48;
        playerSprite.setTextureRect(sf::IntRect(countWidthRight,192,46,96));
        playerSprite.move(0.0f,playerSpeed);

        playerSprite.getPosition();
        stopLeft=false;
        stopUp=false;
        stopRight=false;
    }
    else
    {
        playerSprite.move(0.0f,0.0f);
        stopLeft=false;
        stopUp=false;
        stopRight=false;
    }
    ///pressedDown=true;
}
void Player::moveUp()
{
    if(stopUp==false)
    {


        if(countWidthRight>=336)
        {
            countWidthRight=0;
        }
        else
            countWidthRight+=48;
        playerSprite.setTextureRect(sf::IntRect(countWidthRight,96,46,96));


        playerSprite.move(0.0f,-playerSpeed);
        playerSprite.getPosition();

        stopLeft=false;
        stopDown=false;
        stopRight=false;
    }
    else
    {
        playerSprite.move(0.0f,0.0f);
        stopLeft=false;
        stopDown=false;
        stopRight=false;
    }
    ///pressedUp=true;
}
void Player::moveLeft()
{
    if(stopLeft==false)

    {


        if(countWidthLeft<=48)
        {
            countWidthLeft=384;
        }
        else
        {
            countWidthLeft-=48;
        }
        playerSprite.setTextureRect(sf::IntRect(countWidthLeft,0,-48,96));
        playerSprite.move(-playerSpeed,0.0f);


        playerSprite.getPosition();
        stopRight=false;
        stopDown=false;
        stopUp=false;

    }
    else
    {
        playerSprite.move(0.0f,0.0f);
        stopRight=false;

        stopDown=false;
        stopUp=false;
    }
    /// pressedLeft=true;
}

void Player::getPosition()
{
    cout<<"player position X"<<playerSprite.getPosition().x<<endl;
    cout<<"player position Y"<<playerSprite.getPosition().y <<endl;

}
void Player::wallCollisionDetection()
{
    if (playerSprite.getPosition().x<385.0f)
    {
        playerSprite.setPosition(385.0f,playerSprite.getPosition().y);
    }
    if (playerSprite.getPosition().y<80.0f)
    {
        playerSprite.setPosition(playerSprite.getPosition().x,80.0f);
    }
    if (playerSprite.getPosition().x>1040.0f)
    {
        playerSprite.setPosition(1040.0f,playerSprite.getPosition().y);
    }
    if (playerSprite.getPosition().y>755.0f)
    {
        playerSprite.setPosition(playerSprite.getPosition().x,755.0f);
    }




}
void Player::permanentBlockCollisionDetection(Perblock permanentBlock,char keyEntered)
{
    for(int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            float dx=(playerSprite.getPosition().x)-(permanentBlock.pblockSprite[i][j].getPosition().x);
            float  dy=(playerSprite.getPosition().y)-(permanentBlock.pblockSprite[i][j].getPosition().y);

            if(abs(dx)<40&& abs(dy)<40)
            {
                if(((dx<0&&dy>0)||(dx<0&&dy<0))&&keyEntered=='D')
                {
                    stopRight=true;


                }

                if(((dx>0&&dy>0)||(dx>0&&dy<0))&&keyEntered=='A')
                {
                    stopLeft=true;


                }
                if(((dx<0&&dy>0)||(dx>0&&dy>0))&&keyEntered=='W')
                {
                    stopUp=true;
                }

                if(((dx>0&&dy<0)||(dx<0&&dy<0))&&keyEntered=='S')
                {

                    stopDown=true;

                }






            }


        }
    }
}
void Player::enemyCollisionDetection(sf::Sprite &enemy11,sf::Sprite &enemy22,float x,float y)
{
    float dx11=playerSprite.getPosition().x-enemy11.getPosition().x;
    float dy11=playerSprite.getPosition().y-enemy11.getPosition().y;
    float dx22=playerSprite.getPosition().x-enemy22.getPosition().x;
    float dy22=playerSprite.getPosition().y-enemy22.getPosition().y;


//    if(playerSprite.getGlobalBounds().intersects(enemy11.getGlobalBounds())||playerSprite.getGlobalBounds().intersects(enemy22.getGlobalBounds()))
//    {
//        playerSprite.setPosition(2000,2000);
//    }
    if(abs(dx11)<40&& abs(dy11)<30||abs(dx22)<40&& abs(dy22)<30)
    {
        playerSprite.setPosition(x,y);
        lifeCount--;
    }
}


void Player::temporaryBlockCollisionDetection(tempBlock temporaryBlock,char keyEnt)
{
    for(int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            float dx=(playerSprite.getPosition().x)-(temporaryBlock.tblockSprite[i][j].getPosition().x);
            float  dy=(playerSprite.getPosition().y)-(temporaryBlock.tblockSprite[i][j].getPosition().y);

            if(abs(dx)<40&& abs(dy)<40)
            {
                if(((dx<0&&dy>0)||(dx<0&&dy<0))&&keyEnt=='D')
                {
                    stopRight=true;


                }

                if(((dx>0&&dy>0)||(dx>0&&dy<0))&&keyEnt=='A')
                {
                    stopLeft=true;


                }
                if(((dx<0&&dy>0)||(dx>0&&dy>0))&&keyEnt=='W')
                {
                    stopUp=true;
                }

                if(((dx>0&&dy<0)||(dx<0&&dy<0))&&keyEnt=='S')
                {

                    stopDown=true;

                }






            }


        }
    }
}
void Player::portalMovement(tempBlock portalBlock)
{


    if(abs(playerSprite.getPosition().x-portalBlock.portalSprite[0].getPosition().x)<=10.f && abs(playerSprite.getPosition().y-portalBlock.portalSprite[0].getPosition().y)<=10.f &&(!hasTeleported))
    {
        playerSprite.setPosition(portalBlock.portalSprite[1].getPosition().x-10.f,portalBlock.portalSprite[1].getPosition().y);
        hasTeleported=true;
    }
    if (abs(playerSprite.getPosition().x-portalBlock.portalSprite[1].getPosition().x)<=10.f&&abs(playerSprite.getPosition().y-portalBlock.portalSprite[1].getPosition().y)<=10.f&&(!hasTeleported))
    {
        playerSprite.setPosition(portalBlock.portalSprite[0].getPosition().x+10.f,portalBlock.portalSprite[0].getPosition().y);
        hasTeleported=true;
    }


    hasTeleported=false;


}
void Player::displayPlayerLife(sf::RenderWindow &win)
{

    lifeSprite[0].setTextureRect(sf::IntRect(384,0,-(48*lifeCount),96));

    // lifeSprite[1].setTextureRect(sf::IntRect(0,0,192,96));

    win.draw(lifeSprite[0]);




}









