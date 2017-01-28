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
#include <nyra/zip/Format.h>
#include <nyra/test/Test.h>

namespace nyra
{
namespace zip
{
TEST(Format, FromFile)
{
    EXPECT_EQ(ZIP, fileToFormat("/home/user/test.zip"));
    EXPECT_EQ(GZIP, fileToFormat("/home/user/test.tar.gz"));
    EXPECT_EQ(BZIP2, fileToFormat("/home/user/test.tar.bz2"));
    EXPECT_EQ(SEVEN_ZIP, fileToFormat("/home/user/test.7z"));
    EXPECT_EQ(TAR, fileToFormat("/home/user/test.tar"));
    EXPECT_ANY_THROW(fileToFormat("/home/user/test.txt"));
}
}
}

NYRA_TEST()
