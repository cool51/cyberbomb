
#include<SFML/Graphics.hpp>
#include<Perblock.h>
#include<tempBlock.h>

class CyberMan

{
protected:
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    int playerLife=0;
    float playerSpeed;
    sf::Sprite lifeSprite[2];
public:
    Player(float x,float y,sf::Color rang);
    sf::    Sprite getPlayerSprite();
    void getPosition();
    void displayPlayerLife(sf::RenderWindow &win);
    void portalMovement(tempBlock portalBlock);
    void getLifeSprite();
    void wallCollisionDetection();
    void permanentBlockCollisionDetection(Perblock permanentBlock,char keyEntered);
    void temporaryBlockCollisionDetection(tempBlock temporaryBlock,char keyEnt);



};
