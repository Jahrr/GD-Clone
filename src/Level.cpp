//
// Created by 24CRickenbach on 1/9/2023.
//

#include <iostream>
#include "Level.h"

enum BlockTypes{
    BLOCK = 1,
    SPIKE
};


Level::Level(const LevelLayout& layout) : m_levelLayout{layout}{
    //TODO: Use shared ptr instead of raw pointer
    int i = 0;
    for(int y = 0; y < layout.size(); y++){
        for(int x = 0; x < layout[y].size(); x++){


            switch(layout[y][x]){
                case BLOCK: {
                    auto* block = new sf::RectangleShape(sf::Vector2f(WORLD_SCALE, WORLD_SCALE));
                    block->setFillColor(sf::Color::Black);
                    block->setOutlineThickness(-3);
                    block->setOutlineColor(sf::Color::White);
                    block->setPosition(float(x) * WORLD_SCALE, float(y) * WORLD_SCALE);
                    m_level.push_back(reinterpret_cast<LevelElement *const>(block));
                    m_level[i]->setElementType(0);
                    i++;
                    break;
                }
                case SPIKE:{
                    auto* spike = new sf::ConvexShape(3);
                    float scale = 0.9;
                   // spike->setOrigin(sf::Vector2f(float(WORLD_SCALE)/2.f, float(WORLD_SCALE)/2.f));

                    spike->setPoint(0, sf::Vector2f(float(x) * float(WORLD_SCALE) + float(WORLD_SCALE)/2.f,
                                                   float(y) * WORLD_SCALE));
                    spike->setPoint(1, sf::Vector2f(float(x) * float(WORLD_SCALE),
                                                    float(y) * WORLD_SCALE + WORLD_SCALE));
                    spike->setPoint(2, sf::Vector2f(float(x) * float(WORLD_SCALE) + WORLD_SCALE,
                                                    float(y) * WORLD_SCALE + WORLD_SCALE));
                    std::cout<<spike->getPosition().x << ' '<<spike->getPosition().y<<'\n';

                    spike->setFillColor(sf::Color::Black);
                    spike->setOutlineColor(sf::Color::White);
                    spike->setOutlineThickness(-3);

                    m_level.push_back(reinterpret_cast<LevelElement *const>(spike));
                    m_level[i]->setElementType(1);
                    i++;
                }




                    break;
                default:
                    break;
            }
        }

    }
}

Level::~Level() {
    for(auto i : m_level){
        delete i;
    }

}

void Level::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(auto& i : m_level){
        target.draw(*i);
    }
}

const std::vector<LevelElement*> &Level::getLevel() const {
    return m_level;
}
