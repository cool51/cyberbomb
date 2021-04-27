#ifndef IPLAYER_H
#define IPLAYER_H
#include<AbstractPlayer.h>
#include<Perblock.h>
#include<tempBlock.h>

class Iplayer:public AbstractPlayer
{
    public:
        Iplayer();
        sf::Sprite getPlayerSprite();
          wallCollisionDetection();
    void permanentBlockCollisionDetection(Perblock permanentBlock,char keyEntered);
    void temporaryBlockCollisionDetection(tempBlock temporaryBlock,char keyEnt);
    void portalMovement(tempBlock portalBlock);
    void  getLifeSprite();

        void displayPlayerLife(sf::RenderWindow &win);
         void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();


};

#endif // IPLAYER_H
