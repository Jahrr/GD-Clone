//
// Created by 24CRickenbach on 1/11/2023.
//

#ifndef GD_CAMERA_H
#define GD_CAMERA_H
#include <SFML/Graphics.hpp>

class Camera {

public:
    Camera();
    Camera(sf::Vector2f cameraSize);
    void setCenter(sf::Vector2f center);
    void setTargetWithGDCamera(const sf::Transformable& target);
    void setSize(sf::Vector2f cameraSize);
    void manageCamera(sf::RenderWindow& window);
private:
    sf::View m_cameraView;
    sf::FloatRect m_options;
};


#endif //GD_CAMERA_H
