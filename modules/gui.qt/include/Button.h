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
#ifndef __NYRA_GUI_QT_BUTTON_H__
#define __NYRA_GUI_QT_BUTTON_H__

#include <nyra/gui/qt/TextWidget.h>
#include <QPushButton>

namespace nyra
{
namespace gui
{
namespace qt
{
/*
 *  \class Button
 *  \brief A class used to render a clickable button.
 */
class Button : public QObject, public TextWidget<QPushButton>
{
    Q_OBJECT

public:
    /*
     *  \func Constructor
     *  \brief Creates a default Button.
     *
     *  \param size The size of the Widget
     *  \param position The position of the Widget
     *  \param text The beginning text for the Widget.
     */
    Button(const math::Vector2F& size,
           const math::Vector2F& position,
           const std::string& text = "");

private slots:
    void buttonPressed() const;
};
}
}
}

#endif
