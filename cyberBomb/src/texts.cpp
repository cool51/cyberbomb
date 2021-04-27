#include"Bomb.h"
#include "texts.h"
#include<SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<ctype.h>


texts::texts()
{
    font.loadFromFile("Font.ttf");
    text.setFont(font);
    text.setCharacterSize(50);
    text.setStyle(sf::Text::Italic);
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(0.0f,10.0f);
    text2.setFont(font);
    text2.setCharacterSize(50);
    text2.setStyle(sf::Text::Italic);
    text2.setFillColor(sf::Color::Yellow);
    text2.setPosition(1200.0f,10.0f);


}

void texts:: display_text(sf::RenderWindow &scr, std::string state,Bomb &boomb,Bomb &boomb2)
{

    std::stringstream ss;
    std::stringstream ss1;
//    ss<<"Score 1: "<<boomb.countScore;
//    ss1<<"Score 2:"<<boomb2.countScore2;

    if (state == "Score")

    {
        text.setString(ss.str());
        text2.setString(ss1.str());
    }

    scr.draw(text);
    scr.draw(text2);

}

