//
// Created by 24CRickenbach on 1/11/2023.
//

#include "LevelElement.h"

void LevelElement::setElementType(int type) {
    m_elementType = type;
}

const int &LevelElement::getElementType() {
    return m_elementType;
}
