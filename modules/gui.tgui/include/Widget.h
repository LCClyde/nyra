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
#ifndef __NYRA_GUI_TGUI_WIDGET_H__
#define __NYRA_GUI_TGUI_WIDGET_H__

#include <TGUI/TGUI.hpp>
#include <nyra/gui/Widget.h>
#include <nyra/gui/tgui/GlobalHandler.h>
#include <nyra/mem/GlobalDependency.h>

namespace nyra
{
namespace gui
{
namespace tgui
{
/*
 *  \class Widget
 *  \brief A base class for CEGUI widgets.
 */
class Widget : public virtual gui::Widget
{
public:
    /*
     *  \func Destructor
     *  \brief Necessary for inheritance.
     */
    virtual ~Widget() = default;

    /*
     *  \func setSize
     *  \brief Sets the size of the widget in pixels.
     *
     *  \param size The desired size.
     */
    void setSize(const math::Vector2F& size) override;

    /*
     *  \func setPosition
     *  \brief Sets the position of the widget in pixels.
     *
     *  \param position The desired position.
     */
    void setPosition(const math::Vector2F& position) override;

    /*
     *  \func getPosition
     *  \brief Gets the current position.
     *
     *  \return The value of the position.
     */
    math::Vector2F getPosition() const override;

    /*
     *  \func getSize
     *  \brief Gets the current size.
     *
     *  \return The value of the size.
     */
    math::Vector2F getSize() const override;

    /*
     *  \func setVisible
     *  \brief Sets if a widget is rendered
     *
     *  \param value True if the widget should be rendered
     */
    void setVisible(bool value) override
    {
        // Not yet implemented
    }

    /*
     *  \func getVisible
     *  \brief Is the widget being rendered?
     *
     *  \return True if the widget is visible
     */
    bool getVisible() const override
    {
        // Not yet implemented
        return true;
    }

    /*
     *  \func addChild
     *  \brief Adds a new child widget to this widget.
     *
     *  \param child The widget to add.
     */
    void addChild(gui::Widget& child) override;

    /*
     *  \func getNative
     *  \brief Returns the underlying CEGUI object.
     *
     *  \return The CEGUI Window.
     */
    void* getNative() override
    {
        return &mWidget;
    }

    void setNative(::tgui::Widget::Ptr widget)
    {
        mWidget = widget;
    }

protected:
    ::tgui::Widget::Ptr mWidget;
};
}
}
}

#endif
