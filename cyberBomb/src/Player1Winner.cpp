#include "Player1Winner.h"

PlayerWinner::PlayerWinner()
{
    player1WinnerTexture.loadFromFile("player1Winner.png");
    player1WinnerSprite.setTexture(player1WinnerTexture);
    player2WinnerTexture.loadFromFile("player2Winner.png");
    player2WinnerSprite.setTexture(player2WinnerTexture);
}

void PlayerWinner::loadPlayer1WinnerSprite(sf::RenderWindow &window)
{
    window.draw(player1WinnerSprite);
}

void PlayerWinner::loadPlayer2WinnerSprite(sf::RenderWindow &window)
{
    window.draw(player2WinnerSprite);
}

