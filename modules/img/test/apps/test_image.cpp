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
#include <nyra/img/Image.h>
#include <nyra/test/Test.h>
#include <nyra/core/Archive.h>
#include <nyra/core/Path.h>
#include <nyra/test/Image.h>

namespace
{
//===========================================================================//
class IncPixel
{
public:
    IncPixel() :
        mValue(0)
    {
    }

    double operator()(double x, double y) const
    {
        return static_cast<double>(mValue++);
    }

private:
    mutable uint8_t mValue;
};
}

namespace nyra
{
namespace img
{
//===========================================================================//
TEST(Image, ColorValues)
{
    const math::Vector2U size(32, 32);
    Image image(size);

    for (size_t ii = 0; ii < size.product(); ++ii)
    {
        image(ii) = Color(255, 0, 0, 255);
    }
    EXPECT_TRUE(test::compareImage(image, "test_red.png"));

    for (size_t ii = 0; ii < size.product(); ++ii)
    {
        image(ii) = Color(0, 255, 0, 255);
    }
    EXPECT_TRUE(test::compareImage(image, "test_green.png"));

    for (size_t ii = 0; ii < size.product(); ++ii)
    {
        image(ii) = Color(0, 0, 255, 255);
    }
    EXPECT_TRUE(test::compareImage(image, "test_blue.png"));
}

//===========================================================================//
TEST(Image, Equality)
{
    Image img1;
    img1.resize(math::Vector2U(17, 13));

    Image img2;
    img2.resize(math::Vector2U(16, 12));

    EXPECT_FALSE(img1 == img2);
    EXPECT_TRUE(img1 != img2);

    img2.resize(math::Vector2U(17, 13));

    EXPECT_TRUE(img1 == img2);
    EXPECT_FALSE(img1 != img2);

    img1(2, 5) = Color(23, 45, 67);
    img1(7, 9) = Color(87, 65, 43);

    EXPECT_FALSE(img1 == img2);
    EXPECT_TRUE(img1 != img2);

    img2(2, 5) = Color(23, 45, 67);
    img2(7, 9) = Color(87, 65, 43);

    EXPECT_TRUE(img1 == img2);
    EXPECT_FALSE(img1 != img2);
}

//===========================================================================//
TEST(Image, Constructor)
{
    Image img1;
    EXPECT_EQ(img1.getSize(), math::Vector2U(0, 0));

    const math::Vector2U size(17, 13);
    Image img2(size);

    EXPECT_EQ(img2.getSize(), size);
    for (size_t ii = 0; ii < size.product(); ++ii)
    {
        EXPECT_EQ(img2(ii), Color::BLACK);
    }

    srand(0);
    std::vector<uint8_t> colors(size.product() * 4);
    for (size_t ii = 0; ii < colors.size(); ++ii)
    {
        colors[ii] = rand() % 256;
    }

    Image img3(colors.data(), size);
    for (size_t ii = 0, color = 0; ii < size.product(); ++ii, color += 4)
    {
        EXPECT_EQ(img3(ii), Color(colors[color],
                                  colors[color + 1],
                                  colors[color + 2],
                                  colors[color + 3]));
    }

    IncPixel incer;
    Image imgFunc(incer, size, 0, 255);
    for (size_t ii = 0; ii < size.product(); ++ii)
    {
        const uint8_t val = static_cast<uint8_t>(ii);
        EXPECT_EQ(Color(val, val, val, 255), imgFunc(ii));
    }
}

//===========================================================================//
TEST(Image, ARGB)
{
    const math::Vector2U size(17, 13);
    std::vector<uint8_t> argb(size.product() * 4);
    for (size_t ii = 0; ii < argb.size(); ii += 4)
    {
        argb[ii] = 255;     // alpha
        argb[ii + 1] = 128; // red
        argb[ii + 2] = 64;  // green
        argb[ii + 3] = 32;  // blue
    }

    Image image(argb.data(), size, Image::ARGB);
    for (size_t ii = 0; ii < size.product(); ++ii)
    {
        EXPECT_EQ(Color(128, 64, 32, 255), image(ii));
    }
}

//===========================================================================//
TEST(Image, BGRA)
{
    const math::Vector2U size(17, 13);
    std::vector<uint8_t> bgra(size.product() * 4);
    for (size_t ii = 0; ii < bgra.size(); ii += 4)
    {
        bgra[ii] = 32;      // blue
        bgra[ii + 1] = 64;  // green
        bgra[ii + 2] = 128; // red
        bgra[ii + 3] = 255; // alpha
    }

    Image image(bgra.data(), size, Image::BGRA);
    for (size_t ii = 0; ii < size.product(); ++ii)
    {
        EXPECT_EQ(Color(128, 64, 32, 255), image(ii));
    }
}

//===========================================================================//
TEST(Image, RGB)
{
    const math::Vector2U size(17, 13);
    std::vector<uint8_t> rgb(size.product() * 3);
    for (size_t ii = 0; ii < rgb.size(); ii += 3)
    {
        rgb[ii] = 128;     // red
        rgb[ii + 1] = 64;  // green
        rgb[ii + 2] = 32;  // blue
    }

    Image image(rgb.data(), size, Image::RGB);
    for (size_t ii = 0; ii < size.product(); ++ii)
    {
        EXPECT_EQ(Color(128, 64, 32, 255), image(ii));
    }
}

//===========================================================================//
TEST(Image, BGR)
{
    const math::Vector2U size(17, 13);
    std::vector<uint8_t> bgr(size.product() * 3);
    for (size_t ii = 0; ii < bgr.size(); ii += 3)
    {
        bgr[ii] = 32;      // blue
        bgr[ii + 1] = 64;  // green
        bgr[ii + 2] = 128; // red
    }

    Image image(bgr.data(), size, Image::BGR);
    for (size_t ii = 0; ii < size.product(); ++ii)
    {
        EXPECT_EQ(Color(128, 64, 32, 255), image(ii));
    }
}

//===========================================================================//
TEST(Image, Index)
{
    const math::Vector2U size(17, 13);
    Image image(size);
    const Color color(12, 34, 56, 78);
    image(20) = color;

    EXPECT_EQ(image(20), color);
    EXPECT_EQ(image(3, 1), color);
}

//===========================================================================//
TEST(Image, Add)
{
    Image image1(math::Vector2U(256, 256));
    Image image2(math::Vector2U(256, 256));

    for (size_t ii = 0; ii < 256; ++ii)
    {
        for (size_t jj = 0; jj < 256; ++jj)
        {
            image1(ii, jj) = Color(ii, ii, ii);
            image2(ii, jj) = Color(jj, jj, jj);
        }
    }
    EXPECT_TRUE(test::compareImage(image1 + image2, "test_image_add.png"));
}

//===========================================================================//
TEST(Image, Multiply)
{
    Image image1(math::Vector2U(256, 256));
    Image image2(math::Vector2U(256, 256));

    for (size_t ii = 0; ii < 256; ++ii)
    {
        for (size_t jj = 0; jj < 256; ++jj)
        {
            image1(ii, jj) = Color(ii, ii, ii);
            image2(ii, jj) = Color(jj, jj, jj);
        }
    }
    EXPECT_TRUE(test::compareImage(image1 * image2, "test_image_multiply.png"));
    EXPECT_TRUE(test::compareImage(image1  * Color(255, 0, 0),
                                   "test_image_multiply_color.png"));
}

//===========================================================================//
TEST(Image, ColorAssignment)
{
    srand(0);
    const math::Vector2U size(64, 64);
    Image image(size);

    for (size_t ii = 0; ii < size.product(); ++ii)
    {
        image(ii) = Color(rand() % 255,
                          rand() % 255,
                          rand() % 255,
                          255);
    }

    const Color color(100, 200, 50, 70);
    image = color;

    for (size_t ii = 0; ii < size.product(); ++ii)
    {
        EXPECT_EQ(color, image(ii));
    }
}

//===========================================================================//
TEST(Image, Near)
{
    srand(0);
    const math::Vector2U size(64, 64);
    Image image(size);

    for (size_t ii = 0; ii < size.product(); ++ii)
    {
        image(ii) = Color(rand() % 255,
                          rand() % 255,
                          rand() % 255,
                          255);
    }

    Image compare(image);
    compare(32, 32) = Color::BLACK;

    EXPECT_NE(compare, image);
    EXPECT_TRUE(image.isNear(compare));

    for (size_t ii = 0; ii < 10; ++ii)
    {
        compare(ii) = Color::BLACK;
    }

    EXPECT_FALSE(image.isNear(compare));
}

//===========================================================================//
TEST(Image, Stdout)
{
    Image image;
    EXPECT_EQ(test::stdout(image), "Size: x=0 y=0");

    image.resize(math::Vector2U(2, 2));
    EXPECT_EQ(test::stdout(image),
              "Size: x=2 y=2\n["
              "r=0, g=0, b=0, a=255, | "
              "r=0, g=0, b=0, a=255, | "
              "r=0, g=0, b=0, a=255, | "
              "r=0, g=0, b=0, a=255]");

    image.resize(math::Vector2U(25, 25));
    EXPECT_EQ(test::stdout(image),
              "Size: x=25 y=25\n["
              "r=0, g=0, b=0, a=255, | "
              "r=0, g=0, b=0, a=255, | "
              "r=0, g=0, b=0, a=255, | "
              "r=0, g=0, b=0, a=255, | "
              "r=0, g=0, b=0, a=255]...\n...["
              "r=0, g=0, b=0, a=255, | "
              "r=0, g=0, b=0, a=255, | "
              "r=0, g=0, b=0, a=255, | "
              "r=0, g=0, b=0, a=255, | "
              "r=0, g=0, b=0, a=255]");
}

//===========================================================================//
TEST(Image, Archive)
{
    // Test writing a random image
    srand(0);
    Image imageRand(math::Vector2U(320, 240));
    for (size_t ii = 0; ii < 320 * 240; ++ii)
    {
        imageRand(ii).r = rand() % 256;
        imageRand(ii).g = rand() % 256;
        imageRand(ii).b = rand() % 256;
        imageRand(ii).a = rand() % 256;
    }
    EXPECT_EQ(test::archive(imageRand, "temp.png"), imageRand);

    // Test round trip with an actual 3rd party created png.
    Image imageRoundTrip = core::read<Image>(core::path::join(
            core::DATA_PATH, "textures/test_png.png"));
    EXPECT_EQ(test::archive(imageRoundTrip, "temp.png"), imageRoundTrip);

    EXPECT_ANY_THROW(core::read<img::Image>("something_that_does_not_exist.png"));
}
}
}

NYRA_TEST()
