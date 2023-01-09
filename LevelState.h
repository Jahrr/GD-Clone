//
// Created by 24CRickenbach on 1/9/2023.
//

#ifndef GD_LEVELSTATE_H
#define GD_LEVELSTATE_H
#include "State.h"
#include "Player.h"
class LevelState : public State{

public:
    LevelState();

   void manage() override;

private:
    Player m_player;


};


#endif //GD_LEVELSTATE_H
