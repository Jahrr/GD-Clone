//
// Created by 24CRickenbach on 1/9/2023.
//

#include "Player.h"
#include <iostream>
Player::Player(Level* playerLevelPtr) : m_speed{400}, m_gravity{2000}, m_LevelPtr{playerLevelPtr}, m_jumpForce{700}, m_isOnGround{false}{
    m_playerShape.setSize(sf::Vector2f(WORLD_SCALE,WORLD_SCALE));
    m_playerShape.setFillColor(sf::Color::Blue);
    m_playerShape.setOrigin(m_playerShape.getSize().x/2, m_playerShape.getSize().y/2);
    m_playerShape.setPosition(200, 200);

}

Player::~Player() {

}

void Player::managePlayer() {
    m_playerShape.move(m_velocity.x * m_dt, m_velocity.y * m_dt);
    m_dt = m_clock.restart().asSeconds();

    m_velocity.x = m_speed;
    m_velocity.y += m_gravity * m_dt;
    //TODO: Implement double axis collision
    //bool colliding = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_isOnGround){
        jump();
    }
    for(const auto& i : m_LevelPtr->getLevel()) {
        //TODO: Create collision function
        handleCollisionWithObject(i);
    }
    


}

const sf::Drawable &Player::getPlayerDrawable() {
    return m_playerShape;
}

void Player::jump() {
    m_velocity.y = -m_jumpForce;
}

void Player::die() {
    exit(0);
}

const sf::Transformable &Player::getPlayerTransformable() {
    return m_playerShape;
}

bool Player::handleCollisionWithObject(LevelElement* collisionObject) {
    if (m_playerShape.getGlobalBounds().intersects(collisionObject->getGlobalBounds())){
        if(m_playerShape.getPosition().y < collisionObject->getGlobalBounds().top && m_velocity.y > 0) {
            m_velocity.y = 0;
            m_playerShape.setPosition(m_playerShape.getPosition().x,
                                      collisionObject->getGlobalBounds().top - WORLD_SCALE / 2);
            m_isOnGround = true;
        }else if(m_playerShape.getPosition().x >= collisionObject->getGlobalBounds().left){
            m_velocity.x = 0;
        }else if(m_velocity.y <= 0  ){//m_playerShape.getPosition().y >= collisionObject->getGlobalBounds().top + collisionObject->getGlobalBounds().height - WORLD_SCALE/2 &&
            m_velocity.y = -m_velocity.y;
            m_playerShape.setPosition(m_playerShape.getPosition().x,
                                      collisionObject->getGlobalBounds().top + collisionObject->getGlobalBounds().height + WORLD_SCALE/2);
            std::cout<<"Hit ceiling\n";
        }

        if (collisionObject->getElementType() == 1) {
            die();
        }
        return true;
    }
    m_isOnGround = false;
    return false;
}
