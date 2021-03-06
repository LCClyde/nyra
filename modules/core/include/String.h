/*
 * Copyright (c) 2017 Clyde Stanfield
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to
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
#ifndef __NYRA_CORE_STRING_H__
#define __NYRA_CORE_STRING_H__

#include <string>
#include <vector>

namespace nyra
{
namespace core
{
namespace str
{
/*
 *  \func findAndReplace
 *  \brief Finds all instances of a target string in and replaces it with
 *         another string.
 *
 *  \param input The string to find and replace in. This is purposely copy
 *         constructed because it is modified within the function and
 *         returned.
 *  \param find The string to search for
 *  \param replace The string to replace with
 *  \return The updated string.
 */
std::string findAndReplace(std::string input,
                           const std::string& find,
                           const std::string& replace);

/*
 *  \func toString
 *  \brief Converts a basic type to a string.
 *
 *  \tparam T The type to convert
 *  \param value The value to convert
 *  \return The string representation of the value.
 */
template<typename T>
std::string toString(const T& value);

/*
 *  \func toType
 *  \brief Converts a string to a type
 *
 *  \tparam T The desired type
 *  \param s The string to covert
 *  \return The value
 *  \throw If the string cannot be converted.
 */
template<typename T>
T toType(const std::string& s);

/*
 *  \func split
 *  \brief Splits a string by a delimiter
 *
 *  \param string The string to split
 *  \param delim The delimiter to split by
 *  \return A vector of the parts of the string.
 */
std::vector<std::string> split(const std::string& string,
                               const std::string& delim = " ");

/*
 *  \func startsWith
 *  \brief Checks is a string starts with a value
 *
 *  \param input The string to check
 *  \param start The value to check for
 *  \return True if the string starts with "start"
 */
bool startsWith(const std::string& input,
                const std::string& start);

/*
 *  \func endsWith
 *  \brief Checks is a string ends with a value
 *
 *  \param input The string to check
 *  \param end The ending to check for
 *  \return True if the string ends with "end"
 */
bool endsWith(const std::string& input,
              const std::string& end);

/*
 *  \func lower
 *  \brief Makes a string all lowercase.
 *
 *  \param input The input string
 *  \return The string without any capital letters.
 */
std::string lower(const std::string& input);
}
}
}

#include <nyra/core/String.hpp>

#endif
