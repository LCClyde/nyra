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
#include <Camera.h>

Camera::Camera() :
    mView(sf::Vector2f(640.0f, 360.0f),
          sf::Vector2f(1280.0f, 720.0f)),
    mVelocity(200.0f, 0.0f)
{
}

void Camera::update(float delta)
{
    mView.move(mVelocity * delta);

    const sf::Vector2f& camSize = mView.getSize();
    mRect = sf::FloatRect(mView.getCenter().x - camSize.x / 2.0f,
                          mView.getCenter().y - camSize.y / 2.0f,
                          camSize.x,
                          camSize.y);
}

void Camera::setActive(sf::RenderWindow& target)
{
    target.setView(mView);
}
