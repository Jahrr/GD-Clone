//
// Created by 24CRickenbach on 1/9/2023.
//

#include "Player.h"
#include <iostream>
Player::Player(Level* playerLevelPtr) : m_speed{100}, m_gravity{1000}, m_LevelPtr{playerLevelPtr}, m_jumpForce{700}, m_isOnGround{true}{
    m_playerShape.setSize(sf::Vector2f(WORLD_SCALE,WORLD_SCALE));
    m_playerShape.setFillColor(sf::Color::Blue);
    m_playerShape.setOrigin(m_playerShape.getSize().x/2, m_playerShape.getSize().y/2);
    m_playerShape.setPosition(200, 500);

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
    //m_isOnGround = false;
    for(const auto& i : m_LevelPtr->getLevel()) {
        //TODO: Create collision function
        handleCollisionWithObject(i);
    }
    //In GD every jump the player rotates 180
    m_isOnGround = m_velocity.y == 0;

    if(!m_isOnGround){
        //m_playerShape.rotate(180.f/(((m_jumpForce)/(m_gravity*m_dt))));
        //m_playerShape.rotate(87.5f/((m_velocity.y/(m_gravity*m_dt))));
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
        if( m_velocity.y > 0) {
            m_velocity.y = 0;
            m_playerShape.setPosition(m_playerShape.getPosition().x,
                                      collisionObject->getGlobalBounds().top - WORLD_SCALE/2);
        }else if(m_playerShape.getPosition().x + WORLD_SCALE/2 >= collisionObject->getGlobalBounds().left){
            m_velocity.x = 0;
        }else if(m_velocity.y <= 0){//m_playerShape.getPosition().y >= collisionObject->getGlobalBounds().top + collisionObject->getGlobalBounds().height - WORLD_SCALE/2 &&
            m_velocity.y = 0;
            m_playerShape.setPosition(m_playerShape.getPosition().x,
                                      collisionObject->getGlobalBounds().top + 100);
            std::cout<<"Hit ceiling\n";
        }

        if (collisionObject->getElementType() == 1) {
            die();
        }

        return true;

    }
    return false;
}
