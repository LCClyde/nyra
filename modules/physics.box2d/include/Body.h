/*
 * Copyright (c) 2017 Clyde Stanfield
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
#ifndef __NYRA_PHSYICS_BOX_2D_BODY_H__
#define __NYRA_PHSYICS_BOX_2D_BODY_H__

#include <Box2D/Box2D.h>
#include <nyra/physics/Body.h>
#include <nyra/math/Transform.h>
#include <nyra/physics/box2d/World.h>

namespace nyra
{
namespace physics
{
namespace box2d
{
/*
 *  \class Body
 *  \brief A Box2D physics body object
 */
class Body : public virtual Body2D
{
public:
    /*
     *  \func Constructor
     *  \brief Creates a Box2D body object
     *
     *  \param type The physics type
     *  \param mask The collision mask
     *  \param transform The transform the body is in charge of
     *  \param world The physics world
     *  \param density The object density
     *  \param friction The object friction
     */
    Body(Type type,
         uint64_t mask,
         math::Transform2D& transform,
         World& world,
         double density,
         double friction);

    ~Body();

    /*
     *  \func addCircle
     *  \brief Adds circle collision
     *
     *  \param radius The radius of the circle, pixels
     *  \param offset The offset of the circle, pixels
     */
    void addCircle(double radius,
                   const math::Vector2F& offset) override;

    /*
     *  \func addBox
     *  \brief Adds box collision
     *
     *  \param size The size of the box, pixels
     *  \param offset The offset of the circle, pixels
     */
    void addBox(const math::Vector2F& size,
                const math::Vector2F& offset) override;

    /*
     *  \func update
     *  \brief Updates the body.
     */
    void update() override;

    /*
     *  \func getVelocity
     *  \brief Gets the current linear velocity of the body
     *
     *  \return The velocity vector
     */
    math::Vector2F getVelocity() const;

    /*
     *  \func setVelocity
     *  \brief Sets the linear velocity
     *
     *  \param velocity The desired velocity
     */
    void setVelocity(const math::Vector2F& velocity);

protected:
    void addShape(const b2Shape& shape);

private:
    World& mWorld;
    const double mDensity;
    const double mFriction;
    b2Body* mBody;

protected:
    bool mTrigger;
};
}
}
}

#endif
