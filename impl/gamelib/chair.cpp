#include "chair.hpp"

Chair::Chair(std::shared_ptr<jt::Box2DWorldInterface> world)
{
    b2BodyDef bodyDef;
    bodyDef.fixedRotation = true;
    bodyDef.type = b2_dynamicBody;

    m_physicsObject = std::make_shared<jt::Box2DObject>(world, &bodyDef);
}

void Chair::doCreate()
{
    m_shape = std::make_shared<jt::Shape>();
    m_shape->makeRect({ 32, 16 }, textureManager());
}

void Chair::doUpdate(float const elapsed)
{
    m_shape->setPosition(m_physicsObject->getPosition());
    m_shape->update(elapsed);
}

void Chair::doDraw() const { m_shape->draw(renderTarget()); }
