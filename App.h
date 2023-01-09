//
// Created by 24CRickenbach on 1/9/2023.
//

#ifndef GD_APP_H
#define GD_APP_H
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "LevelState.h"
#include "globals.h"
class App {

public:

    App();
    ~App();

    void run();

private:

    sf::RenderWindow m_window;
    sf::VideoMode m_mode;
    sf::Event m_event;
    StateMachine m_stateMachine;
    LevelState m_levelState;
    sf::Clock m_clock;



    void handleEvents();
    void render();



};


#endif //GD_APP_H
