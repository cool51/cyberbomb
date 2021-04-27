#ifndef PLAYER_H
#define PLAYER_H
#include<SFML/Graphics.hpp>
#include<Perblock.h>
#include<tempBlock.h>
#include<BasePlayer.h>



class Player:public BasePlayer
{

private:
    int num;
    sf::    Vector2f playerPosition;


    sf::Vector2f ScreenResolution;
    int boxSize;
    bool stopUp=false;
    bool stopDown=false;
    bool stopLeft=false;
    bool stopRight=false;
    bool hasTeleported=false;
    float playerSpeed;

public:
    int lifeCount;
    Player(float x,float y,sf::Color rang,float lifeX, float lifeY);
    int countWidthRight;
    int countWidthLeft;

    void getPosition();
    sf::    Vector2f getOrigin();

    sf::Sprite lifeSprite[2];
    void wallCollisionDetection();
    void permanentBlockCollisionDetection(Perblock permanentBlock,char keyEntered);
    void temporaryBlockCollisionDetection(tempBlock temporaryBlock,char keyEnt);
    void enemyCollisionDetection(sf::Sprite &,sf::Sprite &,float,float);
    void portalMovement(tempBlock portalBlock);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
   // int playerLife=0;
    void updatePlayer();

    void displayPlayerLife(sf::RenderWindow &win);
};

#endif // PLAYER_H
