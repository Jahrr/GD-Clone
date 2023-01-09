//
// Created by 24CRickenbach on 1/9/2023.
//

#include "DrawGroup.h"

DrawGroup::DrawGroup()
        : m_drawables{} {

}

void DrawGroup::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(const auto& drawable : m_drawables) {
        target.draw(drawable, states);
    }
}

const sf::Drawable& DrawGroup::operator[](std::size_t index) {
    return m_drawables[index];
}

std::size_t DrawGroup::push_back(const sf::Drawable& drawable) {
    m_drawables.emplace_back(drawable);
    return m_drawables.size() - 1;
}

const sf::Drawable& DrawGroup::pop_back() {
    const auto& drawable = m_drawables.back();
    m_drawables.pop_back();
    return drawable;
}