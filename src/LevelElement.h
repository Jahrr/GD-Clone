//
// Created by 24CRickenbach on 1/11/2023.
//

#ifndef GD_LEVELELEMENT_H
#define GD_LEVELELEMENT_H
#include <SFML/Graphics.hpp>
using sf::Shape;
class LevelElement : public sf::Shape{

public:
    using Shape::Shape;

    void setElementType(int type);
    const int& getElementType();

private:
    int m_elementType;
};


#endif //GD_LEVELELEMENT_H
