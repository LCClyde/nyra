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
#include <nyra/media/BoxArtLoader.h>
#include <nyra/graphics/sfml/Sprite.h>
#include <nyra/core/Path.h>

namespace nyra
{
namespace media
{
//===========================================================================//
BoxArtLoader::BoxArtLoader(std::vector<Game>& games,
                           const std::string& boxArtPath) :
    mGames(games),
    mBoxArtPath(boxArtPath)
{
}

//===========================================================================//
void BoxArtLoader::operator()()
{
    const std::string unknownPathname =
            core::path::join(mBoxArtPath, "../unknown_game.png");
    for (nyra::media::Game& game : mGames)
    {
        if (!game.sprite.get())
        {
            if (!game.boxArtFile.empty())
            {
                game.sprite.reset(new graphics::sfml::Sprite(
                        core::path::join(mBoxArtPath,
                                         game.boxArtFile)));
            }
            else
            {
                game.sprite.reset(
                        new graphics::sfml::Sprite(unknownPathname));
            }
        }
    }
}
}
}
