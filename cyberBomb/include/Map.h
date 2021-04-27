#ifndef MAP_H
#define MAP_H
#include<SFML/Graphics.hpp>

class Map
{
private:
    sf::Texture mapTexture;
    sf::Texture backgroundTexture;

    sf::Texture wallTexture;
    sf::Sprite mapSprite[13][13];
    sf::Sprite wallSprite[13][13];
    sf::Vector2u mapSize;

public:
    Map();
     sf::Sprite backgroundSprite;
    sf::Vector2u getMapSize();
    void DrawMapSprite(sf::RenderWindow& Screen);
    sf::Sprite & getBackgroundSprite();


};

#endif // MAP_H
