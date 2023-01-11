//
// Created by 24CRickenbach on 1/9/2023.
//

#include "App.h"

App::App() : m_mode(sf::VideoMode::getDesktopMode()), m_event(), m_levelState{m_window}{
    m_window.create(m_mode, "Geometry Dash Clone");
    m_window.setVerticalSyncEnabled(true);
    m_stateMachine.pushState(m_levelState);
    m_stateMachine.setState(0);

}

App::~App() = default;

void App::run() {
    while(m_window.isOpen()){
        handleEvents();
        //dt = m_clock.restart().asSeconds();
        m_stateMachine.runState();
        render();
    }
}

void App::handleEvents() {
    if(m_window.pollEvent(m_event)){
        //TODO: add eventHandler class
        switch(m_event.type){
            case sf::Event::Closed:
                m_window.close();
                break;
            default:
                break;
        }
    }
}

void App::render() {

    m_window.clear();
    m_window.draw(m_stateMachine.getCurrentStateDrawGroup());
    m_window.display();
}
