#include "gameMusic.h"
#include<SFML/Audio.hpp>
gameMusic::gameMusic()
{
    bombSoundBUffer.loadFromFile("bombExplosion.wav");
    bombExplosionSound.setBuffer(bombSoundBUffer);
    mainMusic.openFromFile("gameMusic.ogg");

}
void gameMusic:: playBomb()
{
    bombExplosionSound.play();

}
void gameMusic::pauseBomb()
{
    bombExplosionSound.pause();
}
void gameMusic::playMainMusic()
{
    mainMusic.play();
    mainMusic.setLoop(true);
}
void gameMusic::pauseMainMusic()
{
    mainMusic.pause();
}





