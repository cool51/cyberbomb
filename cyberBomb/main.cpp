
#include<SFML/Graphics.hpp>
#include"Player.h"
#include"Map.h"
#include"Perblock.h"
#include"tempBlock.h"
#include"Bomb.h"
#include"gameMusic.h"
#include"Intro.h"
#include"Enemy.h"
#include"Player1Winner.h"
#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
    enum class State {Intro,Playing,Player1Winner,Player2Winner};                              //Different shades of enum just like one with arrays
    State state=State::Intro;

    int bombPlaced11=0;
    int bombPlaced12=0;
    int bombPlaced21=0;
    int bombPlaced22=0;

    gameMusic gMusic;
    gMusic.playMainMusic();


    Player cyberMan(397,100,sf::Color::Cyan,0,50);
    Player cyberMan2(1032,735,sf::Color::Black,1200,50);

    Enemy enemy11(397,735);
    Enemy enemy22(1032,350);

    Map gameMap;
    Perblock pBlock;
    tempBlock tBlock;

    Bomb bomb11;
    Bomb bomb12;
    Bomb bomb21;
    Bomb bomb22;




    sf::Vector2f resolution;
    resolution.x=sf::VideoMode::getDesktopMode().width;
    resolution.y=sf::VideoMode::getDesktopMode().height;
    cout<<"res width"<<resolution.x<<endl;
    cout<<"res width"<<resolution.y<<endl;
    sf::RenderWindow mwindow(sf::VideoMode(resolution.x,resolution.y), "Cyber Bomb",sf::Style::Fullscreen );
    mwindow.setFramerateLimit(120);

    Intro intro(mwindow);
    PlayerWinner pwinner;



    while (mwindow.isOpen())
    {


        enemy11.wallCollisionDetection();
        enemy11.temporaryBlockCollisionDetection(tBlock);
        enemy11.enemyMovement();
        enemy22.wallCollisionDetection();
        enemy22.temporaryBlockCollisionDetection(tBlock);
        enemy22.enemyMovement();
        cyberMan.enemyCollisionDetection(enemy11.enemySprite,enemy22.enemySprite,-100.0f,-100.0f);
        cyberMan2.enemyCollisionDetection(enemy11.enemySprite,enemy22.enemySprite,2000.0f,2000.0f);


        sf::Event event;
        while (mwindow.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyPressed:


                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    mwindow.close();
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&state==State::Playing)
                {
                    cyberMan.wallCollisionDetection();
                    cyberMan.permanentBlockCollisionDetection(pBlock,'W');
                    cyberMan.temporaryBlockCollisionDetection(tBlock,'W');


                    cyberMan.portalMovement(tBlock);
                    cyberMan.moveUp();
                    cout<<"position x :"<<cyberMan.getPlayerSprite().getPosition().x<<"position y : "<<cyberMan.getPlayerSprite().getPosition().y<<endl;


                }



                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)&&state==State::Playing)
                {
                    cyberMan.wallCollisionDetection();
                    cyberMan.permanentBlockCollisionDetection(pBlock,'S');
                    cyberMan.temporaryBlockCollisionDetection(tBlock,'S');
                    cyberMan.portalMovement(tBlock);
                    cyberMan.moveDown();
                    cout<<"position x :"<<cyberMan.getPlayerSprite().getPosition().x<<"position y : "<<cyberMan.getPlayerSprite().getPosition().y<<endl;

                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&state==State::Playing)
                {
                    cyberMan.wallCollisionDetection();
                    cyberMan.permanentBlockCollisionDetection(pBlock,'D');
                    cyberMan.temporaryBlockCollisionDetection(tBlock,'D');
                    cyberMan.portalMovement(tBlock);
                    cyberMan.moveRight();
                    cout<<"position x :"<<cyberMan.getPlayerSprite().getPosition().x<<"position y : "<<cyberMan.getPlayerSprite().getPosition().y<<endl;

                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&state==State::Playing)
                {
                    cyberMan.wallCollisionDetection();
                    cyberMan.permanentBlockCollisionDetection(pBlock,'A');
                    cyberMan.temporaryBlockCollisionDetection(tBlock,'A');
                    cyberMan.portalMovement(tBlock);
                    cyberMan.moveLeft();
                    cout<<"position x :"<<cyberMan.getPlayerSprite().getPosition().x<<"position y : "<<cyberMan.getPlayerSprite().getPosition().y<<endl;

                }


                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&state==State::Playing)
                {
                    cyberMan2.wallCollisionDetection();
                    cyberMan2.permanentBlockCollisionDetection(pBlock,'W');
                    cyberMan2.temporaryBlockCollisionDetection(tBlock,'W');
                    cyberMan2.portalMovement(tBlock);
                    cyberMan2.moveUp();
                    cout<<"position x :"<<cyberMan2.getPlayerSprite().getPosition().x<<"position y : "<<cyberMan.getPlayerSprite().getPosition().y<<endl;


                }



                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&state==State::Playing)
                {
                    cyberMan2.wallCollisionDetection();
                    cyberMan2.permanentBlockCollisionDetection(pBlock,'S');
                    cyberMan2.temporaryBlockCollisionDetection(tBlock,'S');
                    cyberMan2.portalMovement(tBlock);
                    cyberMan2.moveDown();
                    cout<<"position x :"<<cyberMan2.getPlayerSprite().getPosition().x<<"position y : "<<cyberMan.getPlayerSprite().getPosition().y<<endl;

                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&state==State::Playing)
                {
                    cyberMan2.wallCollisionDetection();
                    cyberMan2.permanentBlockCollisionDetection(pBlock,'D');
                    cyberMan2.temporaryBlockCollisionDetection(tBlock,'D');
                    cyberMan2.portalMovement(tBlock);
                    cyberMan2.moveRight();
                    cout<<"position x :"<<cyberMan2.getPlayerSprite().getPosition().x<<"position y : "<<cyberMan2.getPlayerSprite().getPosition().y<<endl;

                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&state==State::Playing)
                {
                    cyberMan2.wallCollisionDetection();
                    cyberMan2.permanentBlockCollisionDetection(pBlock,'A');
                    cyberMan2.temporaryBlockCollisionDetection(tBlock,'A');
                    cyberMan2.portalMovement(tBlock);
                    cyberMan2.moveLeft();
                    cout<<"position x :"<<cyberMan2.getPlayerSprite().getPosition().x<<"position y : "<<cyberMan2.getPlayerSprite().getPosition().y<<endl;

                }

                if(bombPlaced11==0)
                    Sleep(1);

                {

                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&state==State::Playing)
                    {
                        sf::Clock clk;
                        bomb11.setBomb(cyberMan.getPlayerSprite().getPosition());

                    }
                }

                if(bombPlaced12==0)

                {


                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&state==State::Playing)
                    {


                        sf::Clock clk;

                        bomb12.setBomb(cyberMan.getPlayerSprite().getPosition());
                    }
                }




                if(bombPlaced21==0)
                    Sleep(1);
                {

                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)&&state==State::Playing)
                    {
                        sf::Clock clok;
                        bomb21.setBomb(cyberMan2.getPlayerSprite().getPosition());
                    }

                }


                if(bombPlaced22==0)
                {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)&&state==State::Playing)
                    {
                        sf::Clock clok;
                        bomb22.setBomb(cyberMan2.getPlayerSprite().getPosition());
                    }
                }



            }

        }


        bomb11.check(tBlock,cyberMan,cyberMan2,bombPlaced11,cyberMan.lifeCount,cyberMan2.lifeCount);
        bomb12.check(tBlock,cyberMan,cyberMan2,bombPlaced12,cyberMan.lifeCount,cyberMan2.lifeCount);
        bomb21.check(tBlock,cyberMan,cyberMan2,bombPlaced21,cyberMan.lifeCount,cyberMan2.lifeCount);
        bomb22.check(tBlock,cyberMan,cyberMan2,bombPlaced22,cyberMan.lifeCount,cyberMan2.lifeCount);

        if(cyberMan.lifeCount<=0)

        {
            state =State::Player2Winner;
        }

        if(cyberMan2.lifeCount<=0)

        {
            state =State::Player1Winner;
        }

        if(state==State::Intro)
        {

            if(intro.openintro==true)                               //loads the intro, draws it
            {

                mwindow.clear();
                intro.loadIntro();

            }
            if(intro.openintro==false)                              // has to be made false to switch to new state which is done by

            {
                //the x>=1800 -> false in intro cpp file

                state=State::Playing;
            }

        }

        else if(state==State::Player1Winner)
        {
            pwinner.loadPlayer1WinnerSprite(mwindow);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                cyberMan.lifeCount=4;
                cyberMan2.lifeCount=4;
                state=State::Intro;

            }


        }

        else if(state==State::Player2Winner)

        {
            pwinner.loadPlayer2WinnerSprite(mwindow);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                cyberMan.lifeCount=4;
                cyberMan2.lifeCount=4;
                state=State::Intro;
            }

        }



        else if (state==State::Playing)
        {
            mwindow.clear(sf::Color::Transparent);
            mwindow.draw(gameMap.getBackgroundSprite());
            gameMap.DrawMapSprite(mwindow);
            cyberMan.displayPlayerLife(mwindow);
            cyberMan2.displayPlayerLife(mwindow);
            pBlock.DrawPblockSprite(mwindow);
            tBlock.DrawtblockSprite(mwindow);

            mwindow.draw(bomb11.getBombSprite());
            mwindow.draw(bomb12.getBombSprite());
            mwindow.draw(bomb21.getBombSprite());
            mwindow.draw(bomb22.getBombSprite());

            bomb11.DrawFlame(mwindow);
            bomb12.DrawFlame(mwindow);
            bomb21.DrawFlame(mwindow);
            bomb22.DrawFlame(mwindow);


            mwindow.draw(cyberMan.getPlayerSprite());
            mwindow.draw(cyberMan2.getPlayerSprite());
            mwindow.draw(enemy11.getEnemySprite());
            mwindow.draw(enemy22.getEnemySprite());

        }


        mwindow.display();

        cout<<"player 1 life :"<<cyberMan.lifeCount<<endl;
        cout<<"player 2 life :"<<cyberMan2.lifeCount<<endl;

    }

    return 0;
}
