#include "chair.hpp"

#include "game_interface.hpp"
#include "game_properties.hpp"
#include "math_helper.hpp"

Chair::Chair(std::shared_ptr<jt::Box2DWorldInterface> world)
{
    b2BodyDef bodyDef;
    bodyDef.fixedRotation = true;
    bodyDef.type = b2_dynamicBody;
    bodyDef.linearDamping = 1.0;

    m_physicsObject = std::make_shared<jt::Box2DObject>(world, &bodyDef);
    m_physicsObject->setPosition(GP::GetScreenSize() * 0.5f);
    m_forward_vector = jt::Vector2f { 1.0f, 0.0f };
}

void Chair::doCreate()
{
    m_shape = std::make_shared<jt::Shape>();
    m_shape->makeRect({ 16, 16 }, textureManager());
    m_shape->setOrigin(jt::OriginMode::CENTER);
}

void Chair::doUpdate(float const elapsed)
{
    auto const& keyboard = getGame()->input().keyboard();

    auto const forceStrength = 1000.0f;

    if (keyboard->justPressed(jt::KeyCode::A)) {
        m_physicsObject->addForceToCenter(forceStrength * m_forward_vector);
        m_forward_vectorLast = m_forward_vector;
        m_forward_vector = jt::MathHelper::rotateBy(m_forward_vector, -10);
    }
    if (keyboard->justPressed(jt::KeyCode::D)) {
        m_physicsObject->addForceToCenter(forceStrength * m_forward_vector);
        m_forward_vectorLast = m_forward_vector;
        m_forward_vector = jt::MathHelper::rotateBy(m_forward_vector, 10);
    }

    m_shape->setRotation(-jt::MathHelper::angleOf(m_forward_vectorLast));
    m_shape->setPosition(m_physicsObject->getPosition());
    m_shape->update(elapsed);
}

void Chair::doDraw() const { m_shape->draw(renderTarget()); }
