//
// Created by 24CRickenbach on 1/9/2023.
//

#ifndef GD_LEVELSTATE_H
#define GD_LEVELSTATE_H
#include "State.h"
#include "Player.h"
#include "Level.h"
#include "levels.h"
#include "Camera.h"
//TODO: Implement level loader
//Handle Player<->Level interactions here or in level; Currently handling in player
//We can switch levels by creating a pointer to the current level.
//Levels are loaded in by setting pointer to instantiated level(?)
//Only one level loaded until level loader is implemented, we probably only need a function to do this rather than a class.
class LevelState : public State{

public:
    LevelState(sf::RenderWindow& window);

   void manage() override;

private:
    Level* m_currentLevelPtr;
    Player m_player;
    Level m_levelOne;
    Camera m_playerCamera;
};


#endif //GD_LEVELSTATE_H
