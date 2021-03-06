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
#ifndef __NYRA_GRAPHICS_SFML_CAMERA_H__
#define __NYRA_GRAPHICS_SFML_CAMERA_H__

#include <nyra/graphics/Camera.h>
#include <nyra/math/Transform.h>

namespace nyra
{
namespace graphics
{
namespace sfml
{
/*
 *  \class Camera
 *  \brief Class that handles what is rendered to the target.
 */
class Camera : public Camera2D
{
public:
    /*
     *  \func Camera
     *  \brief Sets up the camera object
     *
     *  \param target The target to pull size information from
     */
    Camera(const graphics::RenderTarget& target);

    /*
     *  \func Camera
     *  \brief Sets up the camera object
     *
     *  \param size The render size of the camera
     */
    Camera(const math::Vector2F& size);

    /*
     *  \func render
     *  \brief Sets the camera for rendering
     *
     *  \param target The target to render to.
     */
    void render(graphics::RenderTarget& target) override;

    /*
     *  \func updatesTransform
     *  \brief Updates the camera transform. This is only partially
     *         finished.
     *
     *  \param parent The parent transform
     */
    void updateTransform(const math::Transform2D& parent) override;

private:
    math::Vector2F mGlobalPosition;
};
}
}
}

#endif
