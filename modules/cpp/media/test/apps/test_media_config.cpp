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

#include <nyra/test/Test.h>
#include <nyra/media/Config.h>
#include <nyra/core/Path.h>

namespace nyra
{
namespace media
{
TEST(Config, Defaults)
{
    Config config;

    EXPECT_EQ(Config::DEFAULT_SIZE, config.windowSize);
    EXPECT_EQ(core::DATA_PATH, config.dataPath);
}

TEST(Config, Archive)
{
    Config config;
    const std::string expecedDataPath = "/home/user/data";
    config.dataPath = expecedDataPath;
    const math::Vector2U expectedWindowSize(1280, 720);
    config.windowSize = expectedWindowSize;

    Config archived = test::archive(config);
    EXPECT_EQ(expectedWindowSize, archived.windowSize);
    EXPECT_EQ(expecedDataPath, archived.dataPath);
}

TEST(Config, Stdout)
{
    Config config;
    config.dataPath = "/home/user/config/";
    const std::string expected =
            "Data Path:    /home/user/config/\n"
            "Window Size:  x=1920 y=1080";
    EXPECT_EQ(test::stdout(config), expected);
}
}
}

NYRA_TEST()
