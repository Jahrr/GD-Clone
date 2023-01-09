//
// Created by 24CRickenbach on 1/9/2023.
//


#include "StateMachine.h"

StateMachine::StateMachine() : m_currentState{0}{

}

StateMachine::~StateMachine() {

}

const State &StateMachine::operator[](size_t it) {
    return *m_states[it];
}

void StateMachine::pushState(State &state) {
    m_states.push_back(&state);
}

void StateMachine::setState(size_t stateIt) {
    assert(stateIt <= m_states.size());
    m_currentState = stateIt;
}

size_t StateMachine::popState() {
    m_states.pop_back();
    assert(m_states.size() < m_currentState);
    return m_states.size();

}

void StateMachine::runState() {
    m_states[m_currentState]->manage();
}

const DrawGroup &StateMachine::getCurrentStateDrawGroup() {
    return m_states[m_currentState]->getStateDrawables();
}


