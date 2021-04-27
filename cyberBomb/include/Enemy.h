#ifndef ENEMY_H
#define ENEMY_H
#include<SFML/Graphics.hpp>
#include"tempBlock.h"

class Enemy
{
public:
     sf::Sprite enemySprite;
    Enemy(float x,float y);
    void wallCollisionDetection();
    void enemyMovement();
void temporaryBlockCollisionDetection(tempBlock &temporaryBlock);
 sf::Sprite &getEnemySprite();


protected:

private:
    bool moveUp=false;
    bool moveDown=true;
    bool moveLeft=false;
    bool moveRight=false;

     sf::Texture enemyTexture;

};

#endif // ENEMY_H
