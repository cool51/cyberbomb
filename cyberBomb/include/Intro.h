#ifndef INTRO_H
#define INTRO_H

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>

class Intro
{
public:
    bool openintro = true;
    float xSide = 10.0f	, et;
    Intro(sf::RenderWindow& window) : m_window(window) {};
    void initIntroLoad();
    void loadIntro();

private:
    sf::RenderWindow& m_window;
    float opaque, lPer;
};

#endif // INTRO_H
