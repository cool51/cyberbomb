#include "Enemy.h"

#include<SFML/Graphics.hpp>
Enemy::Enemy(float x,float y)
{
    enemyTexture.loadFromFile("enemy.png");
    enemySprite.setTexture(enemyTexture);
    enemySprite.setOrigin(32,32);
    enemySprite.setPosition(x,y);
    enemySprite.setScale(0.6,0.6);

}

void Enemy::wallCollisionDetection()
{

    if (enemySprite.getPosition().y<80.0f)
    {
        enemySprite.setPosition(enemySprite.getPosition().x,80.0f);
        moveUp=false;
        moveDown=true;
    }


    if (enemySprite.getPosition().y>755.0f)
    {
        enemySprite.setPosition(enemySprite.getPosition().x,755.0f);
        moveUp=true;
        moveDown=false;

    }

}



void Enemy::temporaryBlockCollisionDetection(tempBlock &temporaryBlock)
{
    for(int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            float dx=(enemySprite.getPosition().x)-(temporaryBlock.tblockSprite[i][j].getPosition().x);
            float  dy=(enemySprite.getPosition().y)-(temporaryBlock.tblockSprite[i][j].getPosition().y);

            if(abs(dx)<40&& abs(dy)<40)
            {


                if(((dx<0&&dy>0)||(dx>0&&dy>0)))
                {
                    moveDown=true;
                    moveUp=false;
                }

                if(((dx>0&&dy<0)||(dx<0&&dy<0)))
                {
                    moveUp=true;
                    moveDown=false;

                    ;


                }






            }


        }
    }
}



void Enemy::enemyMovement()
{


    if(moveUp)
    {
        enemySprite.move(0.0f,-1.0f);

    }
    if(moveDown)
    {
        enemySprite.move(0.0f,1.0f);
    }

}
sf::Sprite &Enemy::getEnemySprite()
{
    return enemySprite;
}

