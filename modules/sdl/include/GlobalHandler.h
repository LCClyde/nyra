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
#ifndef __NYRA_SDL_GLOBAL_HANDLER_H__
#define __NYRA_SDL_GLOBAL_HANDLER_H__

#include <SDL2/SDL.h>
#include <nyra/mem/GlobalHandler.h>

namespace nyra
{
namespace sdl
{
/*
 *  \class GlobalHandler
 *  \brief Handles the SDL global init and shutdown commands. All SDL classes
 *         should add a GlobalDependency to this class.
 */
class GlobalHandler : public mem::GlobalHandler
{
private:
    void initializeGlobal() override;

    void shutdownGlobal() override;

    friend std::ostream& operator<<(std::ostream& os,
                                    const GlobalHandler& app);
};
}
}

#endif
