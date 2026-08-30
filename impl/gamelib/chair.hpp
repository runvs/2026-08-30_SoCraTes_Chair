#ifndef CHAIRJAM_CHAIR_HPP
#define CHAIRJAM_CHAIR_HPP

#include "shape.hpp"
#include <game_object.hpp>

class Chair : public jt::GameObject {
public:
    void doCreate() override;
    void doUpdate(float elapsed) override;
    void doDraw() const override;

    std::shared_ptr<jt::Shape> m_shape;
};

#endif // CHAIRJAM_CHAIR_HPP
