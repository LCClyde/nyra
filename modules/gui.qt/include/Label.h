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
#ifndef __NYRA_GUI_QT_LABEL_H__
#define __NYRA_GUI_QT_LABEL_H__

#include <nyra/gui/qt/TextWidget.h>
#include <QLabel>

namespace nyra
{
namespace gui
{
namespace qt
{
/*
 *  \class Label
 *  \brief A class used to render text to the screen.
 */
class Label : public TextWidget<QLabel>
{
public:
    /*
     *  \func Constructor
     *  \brief Creates a default Label.
     *
     *  \param text The beginning text for the widget.
     */
    Label(const std::string& text);

    /*
     *  \func Constructor
     *  \brief Creates a default Label.
     *
     *  \param position The position of the widget.
     *  \param text The beginning text for the widget.
     */
    Label(const math::Vector2F& position,
          const std::string& text);

    /*
     *  \func setText
     *  \brief Sets the text of the widget.
     *
     *  \param text The desired text.
     */
    void setText(const std::string& text) override;
};
}
}
}

#endif
