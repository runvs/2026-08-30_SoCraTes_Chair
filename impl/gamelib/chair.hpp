#ifndef CHAIRJAM_CHAIR_HPP
#define CHAIRJAM_CHAIR_HPP

#include "box2dwrapper/box2d_object.hpp"
#include "shape.hpp"
#include "sprite.hpp"
#include <game_object.hpp>

class Chair : public jt::GameObject {
public:
    explicit Chair(std::shared_ptr<jt::Box2DWorldInterface> world);
    void doCreate() override;
    void doUpdate(float elapsed) override;
    void doDraw() const override;

    std::shared_ptr<jt::Sprite> m_shape;
    std::shared_ptr<jt::Box2DObject> m_physicsObject;
    jt::Vector2f m_forward_vector;
    jt::Vector2f m_forward_vectorLast;
};

#endif // CHAIRJAM_CHAIR_HPP
