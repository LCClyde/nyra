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
#ifndef __NYRA_ZIP_FORMAT_H__
#define __NYRA_ZIP_FORMAT_H__

#include <string>

namespace nyra
{
namespace zip
{
/*
 *  \type Format
 *  \brief Zip types that can be used.
 */
enum Format
{
    AUTO,
    TAR,
    BZIP2,
    GZIP,
    SEVEN_ZIP,
    ZIP
};

/*
 *  \func fileToFormat
 *  \brief Converts a pathname to a zip Format.
 *
 *  \param pathname The pathname of the zip file
 *  \return The Format based on the path extension.
 */
Format fileToFormat(const std::string& pathname);
}
}

#endif
