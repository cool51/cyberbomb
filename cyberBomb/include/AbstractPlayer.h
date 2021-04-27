#ifndef ABSTRACTPLAYER_H
#define ABSTRACTPLAYER_H
#include<SFML/Graphics.hpp>
#include<Perblock.h>
#include<tempBlock.h>

class AbstractPlayer
{
protected:
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    int playerLife=0;
    float playerSpeed;
    sf::Sprite lifeSprite[2];

    bool stopUp=false;
    bool stopDown=false;
    bool stopLeft=false;
    bool stopRight=false;
    bool hasTeleported=false;
      int countWidthRight;
     int countWidthLeft;

public:
    AbstractPlayer();
          sf::    Sprite getPlayerSprite();
    //  void getPosition();
    void displayPlayerLife(sf::RenderWindow &win);
     void  portalMovement(tempBlock portalBlock);
     void  getLifeSprite();
     void wallCollisionDetection();
      void permanentBlockCollisionDetection(Perblock permanentBlock,char keyEntered);
       void temporaryBlockCollisionDetection(tempBlock temporaryBlock,char keyEnt);
     void moveLeft();
     void moveRight();
    void moveUp();
     void moveDown();




};

#endif // ABSTRACTPLAYER_H
