#include "chair.hpp"

#include "game_interface.hpp"
#include "game_properties.hpp"

Chair::Chair(std::shared_ptr<jt::Box2DWorldInterface> world)
{
    b2BodyDef bodyDef;
    bodyDef.fixedRotation = true;
    bodyDef.type = b2_dynamicBody;
    bodyDef.linearDamping = 1.0;

    m_physicsObject = std::make_shared<jt::Box2DObject>(world, &bodyDef);
    m_physicsObject->setPosition(GP::GetScreenSize() * 0.5f);
}

void Chair::doCreate()
{
    m_shape = std::make_shared<jt::Shape>();
    m_shape->makeRect({ 32, 16 }, textureManager());
    m_shape->setOffset(jt::OffsetMode::CENTER);
}

void Chair::doUpdate(float const elapsed)
{
    auto const& keyboard = getGame()->input().keyboard();

    if (keyboard->justPressed(jt::KeyCode::A)) {
        m_physicsObject->addForceToCenter({ 10000.0f, 0.0f });
    }

    m_shape->setPosition(m_physicsObject->getPosition());
    m_shape->update(elapsed);
}

void Chair::doDraw() const { m_shape->draw(renderTarget()); }
