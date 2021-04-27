#ifndef BOMB_H
#define BOMB_H
#include<SFML/Graphics.hpp>
#include"Player.h"
#include"Bomb.h"
#include"tempBlock.h"
#include"gameMusic.h"
#include"Map.h"
#include"texts.h"

class Bomb
{

private :
    bool placed=false;
    sf::Clock clk;
    sf::Time dtime;
    float flameCount;
    float flameCount2;



public:
    gameMusic music;
    sf::Texture BombTexture;
    sf::Sprite BombSprite;
    sf::Texture flameTexture;
    sf::Sprite flameSprite[8][8];
    void DrawFlame(sf::RenderWindow &flameDisplay);
    sf::Sprite &getBombSprite();

    void setBomb(sf::Vector2f );
    Bomb();

    void check(tempBlock &tBlock,Player &player,Player &player2,int &checkBomb,int &p1,int &p2);




};

#endif // BOMB_H
