//
// Created by 24CRickenbach on 1/11/2023.
//

#include "Camera.h"

Camera::Camera() {

}


Camera::Camera(sf::Vector2f cameraSize) {
    m_cameraView.setSize(cameraSize);
}

void Camera::setCenter(sf::Vector2f center) {
    m_cameraView.setCenter(center);
}



void Camera::setSize(sf::Vector2f cameraSize) {
    m_cameraView.setSize(cameraSize);
}

void Camera::setTargetWithGDCamera(const sf::Transformable &target) {
    m_cameraView.setCenter(target.getPosition().x + m_cameraView.getSize().x/3, m_cameraView.getSize().y/2);
}

void Camera::manageCamera(sf::RenderWindow &window) {

    window.setView(m_cameraView);

}



