//
// Created by 24CRickenbach on 1/9/2023.
//

#ifndef GD_LEVEL_H
#define GD_LEVEL_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "globals.h"
#include "LevelElement.h"
class Level : public sf::Drawable{

public:
    explicit Level(const LevelLayout& layout);
    ~Level() override;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    LevelLayout m_levelLayout;
    std::vector<LevelElement*> m_level;
public:
    //Create class LevelElement : public sf::Shape
    const std::vector<LevelElement*> &getLevel() const;


};


#endif //GD_LEVEL_H
