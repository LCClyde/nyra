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

/*
               ..................
...............: STANDARD CODES ::...............
:                                               :\
:   [a?] Alternate       [p?] Pirate            :\
:   [b?] Bad Dump        [t?] Trained           :\
:   [f?] Fixed           [T-] OldTranslation    :\
:   [o?] Overdump        [T+] NewerTranslation  :\
:   [h?] Hack            (-) Unknown Year       :\
:   [!p] Pending Dump    [!] Verified Good Dump :\
:  (M#) Multilanguage (# of Languages)          :\
: (###) Checksum       (??k) ROM Size           :\
:                      (Unl) Unlicensed     :\
:...............................................:\
 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

                .................
................: SPECIAL CODES ::...............
:                                               :\
: .-----Gameboy-----.  .----Super Nintendo----. :\
: [  [C] Color      ]  [ (BS) BS ROMs         ] :\
: [  [S] Super      ]  [ (ST) Sufami Turbo    ] :\
: [ [BF] Bung Fix   ]  [ (NP) Nintendo Power  ] :\
: `-----------------'  `----------------------' :\
:                      .--------Atari---------. :\
: .-----Genesis-----.  [ (PAL) Euro Version   ] :\
: [ (1) Japan       ]  `----------------------' :\
: [ (4) USA         ]  .---------GBA----------. :\
: [ (5) NTSC Only   ]  [ [hI??] Intro hacks   ] :\
: [ [R-] Countries  ]  [ [f_?] EEPROMV124 fix ] :\
: [ (8) PAL Only    ]  `----------------------' :\
: [ (B) non USA     ]  .--------Coleco--------. :\
: [ [c] Checksum    ]  [ (Adam) ADAM Version  ] :\
: [ [x] Bad Checksum]  `----------------------' :\
: `-----------------'                           :\
:                      .--------NES/FC--------. :\
: .--NeoGeo Pocket--.  [ (PC10) PlayChoice 10 ] :\
: [ [M] Mono Only   ]  [   (VS) Versus        ] :\
: `-----------------'  [ [hFFE] FFE Copier fmt] :\
:                      `----------------------' :\
:...............................................:\
 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

                .................
................: COUNTRY CODES ::...............
:                                               :\
:   (1) Japan & Korea      (4) USA & BrazilNTSC :\
:   (A) Australia          (J) Japan            :\
:   (B) non USA (Genesis)  (K) Korea            :\
:   (C) China             (NL) Netherlands      :\
:   (E) Europe            (PD) Public Domain    :\
:   (F) France             (S) Spain            :\
:  (FC) French Canadian   (Sw) Sweden           :\
:  (FN) Finland            (U) USA              :\
:   (G) Germany           (UK) England          :\
:  (GR) Greece           (Unk) Unknown Country  :\
:  (HK) Hong Kong          (I) Italy        :\
:  (D)  Dutch            (Unl) Unlicensed       :\
:...............................................:\
 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

             .......................
.............: STANDARD CODE NOTES ::............
:                                               :\
: [a] This is simply an alternate version of a  :\
:     ROM. Many games have been re-released to  :\
:     fix bugs or even to eliminate Game Genie  :\
:     codes (Yes, Nintendo hates that device).  :\
:             -------------------               :\
: [b] A bad dump often occurs with an older     :\
:     game or a faulty dumper (bad connection). :\
:     Another common source of [b] ROMs is a    :\
:     corrupted upload to a release FTP.        :\
:             -------------------               :\
: [f] A fixed game has been altered in some way :\
:     so that it will run better on a copier    :\
:     or emulator.                              :\
:             -------------------               :\
: [h] Something in this ROM is not quite as it  :\
:     should be. Often a hacked ROM simply has  :\
:     a changed header or has been enabled to   :\
:     run in different regions. Other times it  :\
:     could be a release group intro, or just   :\
:     some kind of cheating or funny hack.      :\
:             -------------------               :\
: [o] An overdumped ROM image has more data     :\
:     than is actually in the cart. The extra   :\
:     information means nothing and is removed  :\
:     from the true image.                      :\
:             -------------------               :\
: [t] A trainer is special code which executes  :\
:     before the game is begun. It allows you   :\
:     to access cheats from a menu.             :\
:             -------------------               :\
: [!] Verified good dump. Thank God for these!  :\
:...............................................:\
 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

             ......................
.............: SPECIAL CODE NOTES ::.............
:                                               :\
: **** SNES ****                                :\
: (BS) These Japanese ROMs were distributed     :\
:      through a satellite system in Japan      :\
:      known as the Broadcast Satellaview.      :\
:      They were transmitted along with a TV    :\
:      show which was connected to the game in  :\
:      some way. These games were only playable :\
:      during the show, and thus stop after an  :\
:      hour, and many were timed so that only   :\
:      certain time periods were playable.      :\
:             -------------------               :\
: (ST) The Sufami Turbo device allowed two      :\
:      GameBoy sized carts to be plugged into   :\
:      the SNES. Certain carts combined into    :\
:      new games much like the Sonic & Knuckles :\
:      lock-on technology by Sega.              :\
:             -------------------               :\
: (NP) Nintendo Power has been known to release :\
:      games only available to its subscribers. :\
:      Most of these ROMs are Japanese, as this :\
:      practice occured mainly in Japan.        :\
:             -------------------               :\
:                                               :\
: **** Genesis ****                             :\
:  (1) Carts with this code will run on both    :\
:      Japanese and Korean machines.            :\
:             -------------------               :\
:  (4) While this code is technically the same  :\
:      as a (U) code, it is a newer header      :\
:      format and represents that the cart will :\
:      run on USA and Brazil NTSC machines.     :\
:             -------------------               :\
:  (B) This country code indicates that the     :\
:      cart will run on any non US machine.     :\
:             -------------------               :\
:  [c] This code represents a cart with known   :\
:      faulty checksum routines.                :\
:             -------------------               :\
:                                               :\
: **** GameBoy ****                             :\
: [BF] Bung released a programmable cartridge   :\
:      compatable with the GameBoy which could  :\
:      hold any data you wished to play.        :\
:      However, many games do not function on   :\
:      Bung v1.0 carts and have to be 'fixed.'  :\
:             -------------------               :\
:                                               :\
: **** Nintendo ****                            :\
: PC10 The PlayChoice 10 was an arcade unit     :\
:      which played exact copies of NES games   :\
:      in an arcade cabinet. The machines had a :\
:      choice of 10 games to choose from and    :\
:      ran for about 3 minutes on 25 cents.     :\
:             -------------------               :\
:                                               :\
:   VS The Versus system ran on similar hard-   :\
:      ware to the PC10 machines, but simply    :\
:      allowed you to play against each other.  :\
:...............................................:\
 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

                   ...........
...................: Credits ::..................
:                                               :\
: Document written by Psych0phobiA / q^-o|o-^p  :\
:                                               :\
: All codes developed by Cowering for the       :\
: Goodxxxx series ROM file renaming utilities.  :\
:                                               :\
: Visit #rareroms on UnitedUsers in IRC!        :\
:...............................................:\
 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
 */

#ifndef __NYRA_MEDIA_GAME_TOKENS_H__
#define __NYRA_MEDIA_GAME_TOKENS_H__

#include <string>
#include <vector>

namespace nyra
{
namespace media
{
/*
 *  \class GameTokens
 *  \brief Parses game filename suffix values.
 */
class GameTokens
{
public:
    /*
     *  \func Constructor
     *  \brief Creates an empty GameTokens
     */
    GameTokens();

    /*
     *  \func Constructor
     *  \brief Creates an initialized GameTokens
     *
     *  \param filename The name to parse
     */
    GameTokens(const std::string& filename);

    /*
     *  \func initialize
     *  \brief Parses a filename
     *
     *  \param filename The name to parse
     */
    void initialize(const std::string& filename);

    /*
     *  \func Less Than Operator
     *  \brief Used to sort GameTokens. More meaningful tokens are
     *         less than "bad" tokens.
     *
     *  \param other The token to compare against
     *  \return True if the GameTokens should be prioritized.
     */
    bool operator<(const GameTokens& other) const;

    /*
     *  \enum Country
     *  \brief Sorted list of countries. Lower value countries are prioritized
     */
    enum Country
    {
        ERROR = -1,
        USA = 0,
        EUROPE,
        JAPAN,
        PUBLIC_DOMAIN,
        USA_AND_BRAZIL,
        ENGLAND,
        AUSTRALIA,
        FRENCH_CANADIAN,
        FRANCE,
        SWEDEN,
        FINLAND,
        GERMANY,
        GREECE,
        NETHERLANDS,
        SPAIN,
        CHINA,
        ITALY,
        DUTCH,
        JAPAN_AND_KOREA,
        NON_USA,
        KOREA,
        HONG_KONG,
        UNLICENSED,
        UNKNOWN_COUNTRY,
    };
private:
    size_t countUnsortedTokens() const;

    friend std::ostream& operator<<(std::ostream& os,
                                    const GameTokens& tokens);

    std::string mAlternative;
    std::string mBadDump;
    std::string mFixed;
    std::string mOverdump;
    std::string mHack;
    std::string mPirate;
    std::string mTrainer;
    std::string mOldTranslation;
    std::string mNewTranslation;
    double mVersion;
    bool mVerifiedGoodDump;
    Country mCountry;
    std::vector<std::string> mMisc;
};
}
}

#endif
