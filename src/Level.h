//
// Created by 24CRickenbach on 1/9/2023.
//

#ifndef GD_LEVEL_H
#define GD_LEVEL_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "globals.h"
class Level : public sf::Drawable{

public:
    Level(const LevelLayout& layout);
    ~Level();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    LevelLayout m_levelLayout;
    std::vector<sf::Shape*> m_level;
public:
    const std::vector<sf::Shape*> &getLevel() const;


};


#endif //GD_LEVEL_H
