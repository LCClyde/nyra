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
#include <nyra/emu/ROM.h>

namespace nyra
{
namespace emu
{
TEST(Memory, ROM8bit)
{
    std::vector<uint8_t> bytes(16);
    for (size_t ii = 0; ii < bytes.size(); ++ii)
    {
        bytes[ii] = ii;
    }

    ROM<uint8_t> rom(bytes.data(), bytes.size());
    for (size_t ii = 0; ii < bytes.size(); ++ii)
    {
        EXPECT_EQ(ii, rom.readWord(ii));
    }

    // Read a few longs
    EXPECT_EQ(static_cast<uint16_t>(0x0201), rom.readLong(1));
    EXPECT_EQ(static_cast<uint16_t>(0x0302), rom.readLong(2));
    EXPECT_EQ(static_cast<uint16_t>(0x0908), rom.readLong(8));

    // Writing to ROM is not allowed.
    EXPECT_ANY_THROW(rom.writeWord(0, 0));
}
}
}

NYRA_TEST()
