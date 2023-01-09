//
// Created by 24CRickenbach on 1/9/2023.
//

#ifndef GD_PLAYER_H
#define GD_PLAYER_H
#include <SFML/Graphics.hpp>
#include "globals.h"
class Player {

public:
    Player();
    ~Player();
    void managePlayer();
    const sf::Drawable& getPlayerDrawable();
private:
    sf::RectangleShape m_playerShape;
    sf::Vector2f m_velocity;
    float m_gravity;
    float m_speed;
    sf::Clock m_clock;

};


#endif //GD_PLAYER_H
