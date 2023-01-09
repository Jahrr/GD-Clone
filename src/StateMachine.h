//
// Created by 24CRickenbach on 1/9/2023.
//

#ifndef GD_STATEMACHINE_H
#define GD_STATEMACHINE_H
#include <vector>
#include <cassert>
#include "State.h"

class StateMachine {

public:
    StateMachine();
    ~StateMachine();
    const State& operator[](size_t it);
    void pushState(State& state);
    void setState(size_t stateIt);
    size_t popState();
    void runState();
    const DrawGroup& getCurrentStateDrawGroup();

private:
    std::vector<State*> m_states;
    size_t m_currentState;

};


#endif //GD_STATEMACHINE_H
