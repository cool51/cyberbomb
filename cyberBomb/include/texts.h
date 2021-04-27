#ifndef TEXTS_H
#define TEXTS_H
#include<SFML/Graphics.hpp>
#include <sstream>
#include<string>
#include"Bomb.h"
class Bomb;
class texts
{
private:
    sf::Font font;
    sf::Text text;
    sf::Text text2;


public:
    texts();

    void display_text(sf::RenderWindow &scr, std::string state,Bomb &boomb,Bomb &boomb2 );


};

#endif // TEXTS_H
