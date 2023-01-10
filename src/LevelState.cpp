//
// Created by 24CRickenbach on 1/9/2023.
//

#include "LevelState.h"


LevelState::LevelState() : m_levelOne{levelOne}, m_currentLevelPtr{&m_levelOne}, m_player(m_currentLevelPtr){
    m_stateDrawables.push_back(m_player.getPlayerDrawable());
    m_stateDrawables.push_back(m_levelOne);
}


void LevelState::manage() {
    m_player.managePlayer();
}

