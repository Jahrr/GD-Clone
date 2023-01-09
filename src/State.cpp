//
// Created by 24CRickenbach on 1/9/2023.
//

#include "State.h"

State::State() = default;

State::~State() = default;

const DrawGroup &State::getStateDrawables() {
    return m_stateDrawables;
}

void State::addDrawable(const sf::Drawable &drawable) {
    m_stateDrawables.push_back(drawable);
}
