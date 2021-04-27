#ifndef PLAYER1WINNER_H
#define PLAYER1WINNER_H
#include<SFML/Graphics.hpp>

class PlayerWinner
{
    public:
        PlayerWinner();
void loadPlayer1WinnerSprite(sf::RenderWindow &window);
void loadPlayer2WinnerSprite(sf::RenderWindow &window);


    protected:

    private:
        sf::Texture player1WinnerTexture;
         sf::Texture player2WinnerTexture;
        sf::Sprite player1WinnerSprite;
        sf::Sprite player2WinnerSprite;
};

#endif // PLAYER1WINNER_H
