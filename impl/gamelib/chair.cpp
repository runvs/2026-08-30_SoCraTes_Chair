#include "chair.hpp"

#include "game_interface.hpp"
#include "game_properties.hpp"
#include "math_helper.hpp"

Chair::Chair(std::shared_ptr<jt::Box2DWorldInterface> world)
{
    b2BodyDef bodyDef;
    bodyDef.fixedRotation = true;
    bodyDef.type = b2_dynamicBody;
    bodyDef.linearDamping = GP::PlayerLinearDamping();

    b2FixtureDef fixtureDef;
    b2PolygonShape boxCollider { };
    boxCollider.SetAsBox(8, 8);
    fixtureDef.shape = &boxCollider;

    m_physicsObject = std::make_shared<jt::Box2DObject>(world, &bodyDef);
    m_physicsObject->getB2Body()->CreateFixture(&fixtureDef);
    m_physicsObject->setPosition({ 30, 30 });
    m_forward_vector = jt::Vector2f { 1.0f, 0.0f };
}

void Chair::doCreate()
{
    m_shape = std::make_shared<jt::Sprite>("assets/chair.png", textureManager());
    m_shape->setOrigin(jt::OriginMode::CENTER);
}

void Chair::doUpdate(float const elapsed)
{
    auto const& keyboard = getGame()->input().keyboard();

    auto const force_strength = GP::PlayerMoveStrength();

    auto const angle_to_turn_in_degrees = GP::PlayerTurnAngleInDegree();

    if (keyboard->justPressed(jt::KeyCode::A)) {
        m_physicsObject->addForceToCenter(force_strength * m_forward_vector);
        m_forward_vectorLast = m_forward_vector;
        m_forward_vector = jt::MathHelper::rotateBy(m_forward_vector, -angle_to_turn_in_degrees);
    }

    if (keyboard->justPressed(jt::KeyCode::D)) {
        m_physicsObject->addForceToCenter(force_strength * m_forward_vector);
        m_forward_vectorLast = m_forward_vector;
        m_forward_vector = jt::MathHelper::rotateBy(m_forward_vector, angle_to_turn_in_degrees);
    }

    m_shape->setRotation(-jt::MathHelper::angleOf(m_forward_vectorLast));
    m_shape->setPosition(m_physicsObject->getPosition());
    m_shape->update(elapsed);
}

void Chair::doDraw() const { m_shape->draw(renderTarget()); }
