#include "chair.hpp"

void Chair::doCreate()
{
    m_shape = std::make_shared<jt::Shape>();
    m_shape->makeRect({ 32, 16 }, textureManager());
}

void Chair::doUpdate(float const elapsed) { m_shape->update(elapsed); }

void Chair::doDraw() const { m_shape->draw(renderTarget()); }
