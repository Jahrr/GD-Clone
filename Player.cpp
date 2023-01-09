//
// Created by 24CRickenbach on 1/9/2023.
//

#include "Player.h"
#include <iostream>
Player::Player() : m_speed{30}, m_gravity{30}{
    m_playerShape.setSize(sf::Vector2f(30,30));
    m_playerShape.setFillColor(sf::Color::Red);
    m_playerShape.setOrigin(m_playerShape.getSize().x/2, m_playerShape.getSize().y/2);
    m_playerShape.setPosition(200, 500);

}

Player::~Player() {

}

void Player::managePlayer() {
    m_velocity.x = m_speed * m_clock.restart().asSeconds();
    m_velocity.y = 0;
    m_playerShape.move(m_velocity);
    std::cout<<m_playerShape.getPosition().x<<'\n';
}

const sf::Drawable &Player::getPlayerDrawable() {
    return m_playerShape;
}
