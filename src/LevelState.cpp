//
// Created by 24CRickenbach on 1/9/2023.
//

#include "LevelState.h"


LevelState::LevelState(sf::RenderWindow& window) : m_levelOne{levelOne}, m_currentLevelPtr{&m_levelOne}, m_player(m_currentLevelPtr){
    m_stateDrawables.push_back(m_player.getPlayerDrawable());
    m_stateDrawables.push_back(m_levelOne);
    m_windowPtr = &window;
    m_playerCamera.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
}


void LevelState::manage() {
    m_player.managePlayer();
    m_playerCamera.setTargetWithGDCamera(m_player.getPlayerTransformable());
    m_playerCamera.manageCamera(*m_windowPtr);
}

