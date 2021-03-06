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
#include <nyra/mtg/Card.h>
#include <nyra/core/String.h>

namespace
{
//===========================================================================//
std::string combineTreeArray(const nyra::mem::Tree<std::string>& tree,
                             const std::string& name)
{
    std::string ret;
    for (size_t ii = 0; ii < tree[name].loopSize(); ++ii)
    {
        if (ii > 0)
        {
            ret += " ";
        }
        ret += tree[name][ii].get();
    }
    return ret;
}
}

namespace nyra
{
namespace mtg
{
//===========================================================================//
Card::Card() :
    rarity(COMMON),
    power(0),
    toughness(0),
    loyalty(0),
    isFlipCard(false),
    isBackside(false),
    mEDHColorsSet(false)
{
}

//===========================================================================//
Card::Card(const mem::Tree<std::string>& tree) :
    power(0),
    toughness(0),
    loyalty(0),
    isFlipCard(false),
    isBackside(false),
    mEDHColorsSet(false)
{
    name = tree["name"].get();
    cost = stringToMana(tree.has("manaCost") ? tree["manaCost"].get() : "");
    text = tree.has("text") ? tree["text"].get() : "";
    rarity = stringToRarity(tree["rarity"].get());
    supertypes = stringToSupertype(tree.has("supertypes") ?
            combineTreeArray(tree, "supertypes") : "");
    types = stringToType(tree.has("types") ?
            combineTreeArray(tree, "types") : "");

    if (tree.has("subtypes"))
    {
        for (size_t ii = 0; ii < tree["subtypes"].loopSize(); ++ii)
        {
            subtypes.push_back(tree["subtypes"][ii].get());
        }
    }

    if (tree.has("power"))
    {
        try
        {
            power = core::str::toType<size_t>(tree["power"].get());
        }
        catch (...)
        {
            power = SPECIAL_VALUE;
        }
    }

    if (tree.has("toughness"))
    {
        try
        {
            toughness = core::str::toType<size_t>(tree["toughness"].get());
        }
        catch (...)
        {
            toughness = SPECIAL_VALUE;
        }
    }

    if (tree.has("loyalty"))
    {
        loyalty = core::str::toType<size_t>(tree["loyalty"].get());
    }

    if (tree.has("names"))
    {
        isFlipCard = true;
        if (name == tree["names"][tree["names"].loopSize() - 1].get())
        {
            isBackside = true;
        }
    }

    removeReminderText();
}

//===========================================================================//
void Card::removeReminderText()
{
    const std::vector<std::string> parts =
            core::str::split(text, "\n");
    std::vector<std::vector<std::string>> textAndReminder;
    text.clear();

    for (size_t ii = 0; ii < parts.size(); ++ii)
    {
        textAndReminder.push_back(core::str::split(parts[ii], " ("));

        if (ii == 0)
        {
            text = textAndReminder[ii][0];
        }
        else
        {
            if (textAndReminder[ii].size() > 1 &&
                    textAndReminder[ii - 1].size() > 1)
            {
                const std::string firstLetter(
                        textAndReminder[ii][0].substr(0, 1));
                const std::string restLetters(
                        textAndReminder[ii][0].substr(1, std::string::npos));
                text += ", " + core::str::lower(firstLetter) + restLetters;
            }
            else
            {
                text += "\n" + textAndReminder[ii][0];
            }
        }
    }
}

//===========================================================================//
bool Card::hasCost() const
{
    return !(cost.size() == 1 && cost[0] == NONE);
}

//===========================================================================//
bool Card::isType(Type type) const
{
    for (size_t ii = 0; ii < types.size(); ++ii)
    {
        if (types[ii] == type)
        {
            return true;
        }
    }

    return false;
}

//===========================================================================//
const std::vector<Mana>& Card::getEDHColors() const
{
    if (!mEDHColorsSet)
    {
        // Special case for basic lands
        if (rarity == BASIC_LAND)
        {
            if (name == "Plains")
            {
                mEDHColors = {WHITE};
            }
            else if (name == "Island")
            {
                mEDHColors = {BLUE};
            }
            else if (name == "Swamp")
            {
                mEDHColors = {BLACK};
            }
            else if (name == "Mountain")
            {
                mEDHColors = {RED};
            }
            else if (name == "Forest")
            {
                mEDHColors = {GREEN};
            }
        }
        else
        {
            std::vector<size_t> foundColors(MAX_MANA);

            for (Mana mana : cost)
            {
                foundColors[mana] += 1;
            }

            // Search text for symbols
            if (text.find("{W}") != std::string::npos)
            {
                foundColors[WHITE] += 1;
            }
            if (text.find("{U}") != std::string::npos)
            {
                foundColors[BLUE] += 1;
            }
            if (text.find("{B}") != std::string::npos)
            {
                foundColors[BLACK] += 1;
            }
            if (text.find("{R}") != std::string::npos)
            {
                foundColors[RED] += 1;
            }
            if (text.find("{G}") != std::string::npos)
            {
                foundColors[GREEN] += 1;
            }

            if (foundColors[WHITE] > 0)
            {
                mEDHColors.push_back(WHITE);
            }
            if (foundColors[BLUE] > 0)
            {
                mEDHColors.push_back(BLUE);
            }
            if (foundColors[BLACK] > 0)
            {
                mEDHColors.push_back(BLACK);
            }
            if (foundColors[RED] > 0)
            {
                mEDHColors.push_back(RED);
            }
            if (foundColors[GREEN] > 0)
            {
                mEDHColors.push_back(GREEN);
            }
        }

        mEDHColorsSet = true;
    }

    return mEDHColors;
}

//===========================================================================//
std::ostream& operator<<(std::ostream& os, const Card& card)
{
    os << "Name: " << card.name << "\n";

    if (card.hasCost())
    {
        os << "Cost: " << manaToString(card.cost) << "\n";
    }

    if (!card.text.empty())
    {
        os << "Text:\n" << card.text << "\n";
    }

    os << "Rarity: " << rarityToString(card.rarity) << "\n";

    if (!card.supertypes.empty())
    {
        os << "Supertype: " << supertypeToString(card.supertypes) << "\n";
    }

    os  << "Type: " << typeToString(card.types);

    if (!card.subtypes.empty())
    {
       os << "\nSubtype: " ;
       for (size_t ii = 0; ii < card.subtypes.size(); ++ii)
       {
           if (ii > 0)
           {
               os << " ";
           }
           os << card.subtypes[ii];
       }
    }

    if (card.isType(CREATURE))
    {
        os << "\nPower: ";
        if (card.power == Card::SPECIAL_VALUE)
        {
            os << "*\n";
        }
        else
        {
            os << card.power << "\n";
        }

        os << "Toughness: ";
        if (card.toughness == Card::SPECIAL_VALUE)
        {
            os << "*";
        }
        else
        {
            os << card.toughness;
        }
    }

    if (card.isType(PLANESWALKER))
    {
        os << "\nLoyalty: " << card.loyalty;
    }

    return os;
}
}
}
