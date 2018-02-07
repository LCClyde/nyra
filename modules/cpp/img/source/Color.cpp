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
#include <nyra/img/Color.h>

namespace
{
//===========================================================================//
double toDouble(uint8_t val)
{
    return val / 255.0;
}

//===========================================================================//
uint8_t toInt(double val)
{
    int32_t newVal = val * 255.0;
    return std::max(std::min(newVal, 255), 0);
}

//===========================================================================//
uint8_t add(uint8_t v1, uint8_t v2, uint8_t a)
{
    return toInt(toDouble(v1) + (toDouble(v2) * toDouble(a)));
}

//===========================================================================//
uint8_t multiply(uint8_t v1, uint8_t v2)
{
    return toInt(toDouble(v1) * toDouble(v2));
}
}

namespace nyra
{
namespace img
{
//===========================================================================//
const Color Color::BLACK(0, 0, 0);
const Color Color::WHITE(255, 255, 255);
const Color Color::GRAY(127, 127, 127);
const Color Color::ALPHA(0, 0, 0, 0);

//===========================================================================//
Color::Color() :
    r(0),
    g(0),
    b(0),
    a(255)
{
}

//===========================================================================//
Color::Color(uint8_t r, uint8_t g, uint8_t b) :
    r(r),
    g(g),
    b(b),
    a(255)
{
}

//===========================================================================//
Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) :
    r(r),
    g(g),
    b(b),
    a(a)
{
}

//===========================================================================//
Color& Color::operator+=(const Color& other)
{
    r = add(r, other.r, other.a);
    g = add(g, other.g, other.a);
    b = add(b, other.b, other.a);
    return *this;
}

//===========================================================================//
Color& Color::operator*=(const Color& other)
{
    r = multiply(r, other.r);
    g = multiply(g, other.g);
    b = multiply(b, other.b);
    a = multiply(a, other.a);
    return *this;
}

//===========================================================================//
uint32_t Color::toRGBA() const
{
    return (r << 24) | (g << 16) | (b << 8) | a;
}

//===========================================================================//
uint32_t Color::toARGB() const
{
    return (a << 24) | (r << 16) | (g << 8) | b;
}

//===========================================================================//
std::ostream& operator<<(std::ostream& os, const Color& color)
{
    os << "r=" << static_cast<uint32_t>(color.r)
       << ", g=" << static_cast<uint32_t>(color.g)
       << ", b=" << static_cast<uint32_t>(color.b)
       << ", a=" << static_cast<uint32_t>(color.a);
    return os;
}
}
}
