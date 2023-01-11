//
// Created by 24CRickenbach on 1/9/2023.
//

#ifndef GD_STATE_H
#define GD_STATE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "DrawGroup.h"
class State {


public:
    State();
    ~State();
    virtual void manage() = 0;
    const DrawGroup& getStateDrawables();

protected:
    DrawGroup m_stateDrawables;
    sf::RenderWindow* m_windowPtr;
    void addDrawable(const sf::Drawable& drawable);
    void setCurrentWindow(sf::RenderWindow& window);
};


#endif //GD_STATE_H
