//
// Created by 24CRickenbach on 1/9/2023.
//

#ifndef GD_PLAYER_H
#define GD_PLAYER_H
#include <SFML/Graphics.hpp>
#include "globals.h"
#include "Level.h"
#include <algorithm>
class Player {

public:
    explicit Player(Level* playerLevelPtr);
    ~Player();
    void managePlayer();
    const sf::Drawable& getPlayerDrawable();
    const sf::Transformable& getPlayerTransformable();

private:
    sf::RectangleShape m_playerShape;
    sf::Vector2f m_velocity;
    float m_gravity;
    float m_speed;
    float m_dt;
    float m_jumpForce;
    bool m_isOnGround;
    sf::Clock m_clock;

    Level* m_LevelPtr;

    void jump();
    void die();

};


#endif //GD_PLAYER_H
