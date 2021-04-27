#include "Map.h"
#include<SFML/Graphics.hpp>
Map::Map()
{
    mapTexture.loadFromFile("BackgroundTile.png");
    wallTexture.loadFromFile("wall.png");
     backgroundTexture.loadFromFile("gameBackGround.png");
     backgroundSprite.setTexture(backgroundTexture);

    float x=299.0f,y=0.0f;
    float wallX=299,wallY=0.0f;

    for(int i = 0; i < 13; i++)
    {

        for(int j=0; j<13; j++)
        {

            mapSprite[i][j].setTexture(mapTexture);
            mapSprite[i][j].setOrigin(0,0);
            mapSprite[i][j].setPosition(x, y);
            y += 64.0f;

        }

        x += 64.0f;
        y = 0.0f;

    }

    for(int i = 0; i < 13; i++)
    {

        for(int j=0; j<13; j++)
        {
            if(i==0||i==12||j==0||j==12)
            {
                wallSprite[i][j].setTexture(wallTexture);
                wallSprite[i][j].setPosition(wallX,wallY);
            }
            wallY+=64.0f;
        }
        wallX+=64.0f;
        wallY=0.0f;


    }
}


sf::Vector2u Map::getMapSize()
{
    mapSize=mapTexture.getSize();
    return mapSize;
}
void Map::DrawMapSprite(sf::RenderWindow &Screen)
{
    for(int i=0; i<13; i++)
    {
        for(int j=0; j<13; j++)
        {

            Screen.draw(mapSprite[i][j]);
            Screen.draw(wallSprite[i][j]);

        }
    }

}
sf::Sprite & Map::getBackgroundSprite()
{
return backgroundSprite;
}




