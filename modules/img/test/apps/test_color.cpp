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
#include <nyra/test/Test.h>
#include <nyra/img/Color.h>

namespace nyra
{
namespace img
{
TEST(Color, Equality)
{
    Color color;
    color.r = 0x56;
    color.g = 0x78;
    color.b = 0x9A;
    color.a = 0xBC;
    EXPECT_TRUE(color == color);

    Color wrong;
    wrong.r = 0x00;
    wrong.g = color.g;
    wrong.b = color.b;
    wrong.a = color.a;
    EXPECT_TRUE(color != wrong);

    wrong.r = color.r;
    wrong.g = 0x00;
    EXPECT_TRUE(color != wrong);

    wrong.g = color.g;
    wrong.b = 0x00;
    EXPECT_TRUE(color != wrong);

    wrong.b = color.b;
    wrong.a = 0x00;
    EXPECT_TRUE(color != wrong);
}

TEST(Color, Constructor)
{
    Color defaultColor;
    EXPECT_EQ(defaultColor.r, static_cast<uint8_t>(0x00));
    EXPECT_EQ(defaultColor.g, static_cast<uint8_t>(0x00));
    EXPECT_EQ(defaultColor.b, static_cast<uint8_t>(0x00));
    EXPECT_EQ(defaultColor.a, static_cast<uint8_t>(0xFF));

    Color rgbColor(0x56, 0x78, 0x9A);
    EXPECT_EQ(rgbColor.r, static_cast<uint8_t>(0x56));
    EXPECT_EQ(rgbColor.g, static_cast<uint8_t>(0x78));
    EXPECT_EQ(rgbColor.b, static_cast<uint8_t>(0x9A));
    EXPECT_EQ(rgbColor.a, static_cast<uint8_t>(0xFF));

    Color rgbaColor(0x56, 0x78, 0x9A, 0xBC);
    EXPECT_EQ(rgbaColor.r, static_cast<uint8_t>(0x56));
    EXPECT_EQ(rgbaColor.g, static_cast<uint8_t>(0x78));
    EXPECT_EQ(rgbaColor.b, static_cast<uint8_t>(0x9A));
    EXPECT_EQ(rgbaColor.a, static_cast<uint8_t>(0xBC));

    Color copyColor(rgbaColor);
    EXPECT_EQ(copyColor.r, static_cast<uint8_t>(0x56));
    EXPECT_EQ(copyColor.g, static_cast<uint8_t>(0x78));
    EXPECT_EQ(copyColor.b, static_cast<uint8_t>(0x9A));
    EXPECT_EQ(copyColor.a, static_cast<uint8_t>(0xBC));

    Color assignColor = rgbaColor;
    EXPECT_EQ(assignColor.r, static_cast<uint8_t>(0x56));
    EXPECT_EQ(assignColor.g, static_cast<uint8_t>(0x78));
    EXPECT_EQ(assignColor.b, static_cast<uint8_t>(0x9A));
    EXPECT_EQ(assignColor.a, static_cast<uint8_t>(0xBC));
}

TEST(Color, Uint32)
{
    Color color(0x56, 0x78, 0x9A, 0xBC);
    EXPECT_EQ(color.toRGBA(), static_cast<uint32_t>(0x56789ABC));
    EXPECT_EQ(color.toARGB(), static_cast<uint32_t>(0xBC56789A));
}

TEST(Color, LERP)
{
    Color c1(32, 64, 128, 255);
    Color c2(255, 128, 64, 32);
    EXPECT_EQ(c1, math::linearInterpolate(c1, c2, 0.0));
    EXPECT_EQ(c2, math::linearInterpolate(c1, c2, 1.0));
    EXPECT_EQ(Color(143, 96, 96, 143), math::linearInterpolate(c2, c1, 0.5));
}

TEST(Color, Archive)
{
    Color color(0x56, 0x78, 0x9A, 0xBC);
    Color archived = test::archive(color);
    EXPECT_EQ(color, archived);
}

TEST(Color, Stdout)
{
    Color color(0x56, 0x78, 0x9A, 0xBC);
    EXPECT_EQ(test::stdout(color), "r=86, g=120, b=154, a=188");
}
}
}

NYRA_TEST()
