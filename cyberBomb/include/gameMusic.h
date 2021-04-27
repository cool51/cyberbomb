#ifndef GAMEMUSIC_H
#define GAMEMUSIC_H
#include<SFML/Audio.hpp>

class gameMusic
{
public:
    sf::SoundBuffer bombSoundBUffer;
    sf::Sound bombExplosionSound;
    sf::Music mainMusic;
    gameMusic();
    void playBomb();

    void pauseBomb();
    void playMainMusic();
    void pauseMainMusic();




};

#endif // GAMEMUSIC_H
