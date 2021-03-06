/*
 * Copyright (c) 2018 Clyde Stanfield
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
#include <nyra/editor/ContentBrowser.h>
#include <nyra/game/Map.h>

namespace nyra
{
namespace editor
{
//===========================================================================//
ContentBrowser::ContentBrowser() :
    DialogWindow("Nyra Content Browser",
                 math::Vector2U(1280, 720),
                 math::Vector2I(30, 30))
{
    mSchemaGui.reset(new SchemaGui("sprite", 0.0, mWindow.getSize().x,
            std::bind(&ContentBrowser::updateSprite, this, std::placeholders::_1), mGui));

}

//===========================================================================//
void ContentBrowser::updateSprite(const json::JSON& tree)
{
    game::Sprite& sprite = dynamic_cast<game::Sprite&>(
            game::Map::getActor("sprite").getRenderable());
    sprite.initialize(tree);
}
}
}

