/*
 * Copyright (c) 2016 Clyde Stanfield
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
#include <nyra/test/RenderTarget.h>
#include <nyra/graphics/gl/RenderTarget.h>
#include <nyra/graphics/gl/Mesh.h>
#include <nyra/win/gl/Window.h>
#include <nyra/core/Path.h>

namespace nyra
{
namespace graphics
{
namespace gl
{
TEST(OpenGLRenderTarget, Temp)
{
    win::gl::Window window("temp",
                           math::Vector2U(256, 256),
                           math::Vector2I(200, 200));
    RenderTarget target(window);
    std::vector<math::Vector3F> vertices;
    vertices.push_back(math::Vector3F(0.5f,  0.5f, 0.0f));
    vertices.push_back(math::Vector3F(0.5f, -0.5f, 0.0f));
    vertices.push_back(math::Vector3F(-0.5f, -0.5f, 0.0f));
    vertices.push_back(math::Vector3F(-0.5f, 0.5f, 0.0f));
    std::vector<size_t> indices;
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(3);
    indices.push_back(1);
    indices.push_back(2);
    indices.push_back(3);
    Mesh mesh(vertices, indices);

    window.update();
    target.clear(img::Color(128, 128, 128));
    mesh.render(target);
    target.flush();

    core::write<img::Image>(target.getPixels(), "test_gl_mesh.png");
    img::Image image = core::read<img::Image>(core::path::join(
            core::DATA_PATH, "textures/test_gl_mesh.png"));
    EXPECT_EQ(image, target.getPixels());
}
}
}
}

NYRA_TEST()
