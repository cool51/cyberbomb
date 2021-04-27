#include "Intro.h"

void Intro::loadIntro()
{
    //Graphics
    sf::Texture introTexture, mainMenuTexture;
    sf::Sprite introSprite, mainMenuSprite;
    introTexture.loadFromFile("LOADING.jpg");
    introSprite.setTexture(introTexture);

    sf::Clock clk;
    et = clk.getElapsedTime().asSeconds();
    system("cls");

    sf::RectangleShape rect(sf::Vector2f(xSide, 5.f));
    rect.setPosition(sf::Vector2f(50.0f, 1020.0f));
    rect.setFillColor(sf::Color::Cyan);

    m_window.draw(introSprite);
    if (xSide < 1800.0f)
    {
        xSide += 200000000.0f * et;
        lPer = (xSide / 1800.0f) * 100;
        m_window.draw(rect);
    }
    if (xSide >= 1800.0f)
    {




        openintro = false;
        // when the loading line crosses position x, open intro goes false.
    }

}
