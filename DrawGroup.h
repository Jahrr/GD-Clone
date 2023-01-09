//
// Created by 24CRickenbach on 1/9/2023.
//

#ifndef GD_DRAWGROUP_H
#define GD_DRAWGROUP_H
#include <SFML/Graphics.hpp>
#include <vector>
class DrawGroup : public sf::Drawable {
public:
    DrawGroup();
    ~DrawGroup() override = default;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    const sf::Drawable& operator[](std::size_t index);
    std::size_t push_back(const sf::Drawable& drawable);
    const sf::Drawable& pop_back();

private:
    std::vector<std::reference_wrapper<const sf::Drawable>> m_drawables;
};

#endif //GD_DRAWGROUP_H
