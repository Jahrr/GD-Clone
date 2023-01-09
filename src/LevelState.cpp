//
// Created by 24CRickenbach on 1/9/2023.
//

#include "LevelState.h"


LevelState::LevelState() {
    m_stateDrawables.push_back(m_player.getPlayerDrawable());
}


void LevelState::manage() {
    m_player.managePlayer();
}

