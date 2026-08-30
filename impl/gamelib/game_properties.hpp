#ifndef GAME_GAMEPROPERTIES_HPP
#define GAME_GAMEPROPERTIES_HPP

#include <color/color.hpp>
#include <color/palette.hpp>
#include <vector.hpp>
#include <string>

class GP {
public:
    GP() = delete;

    static std::string GameName() { return "ChairJam"; }

    static std::string AuthorName() { return "Kat, TobiS, Laguna_999"; }

    static std::string JamName() { return "SoCraTes"; }

    static std::string JamDate() { return "2026"; }

    static std::string ExplanationText() { return "Race the Track\n[A,D, Arrows] to move"; }

    static jt::Vector2f GetWindowSize() { return jt::Vector2f { 1280, 960 }; }

    static float GetZoom() { return 4.0f; }

    static jt::Vector2f GetScreenSize() { return GetWindowSize() * (1.0f / GetZoom()); }

    static jt::Color PaletteBackground() { return GP::getPalette().getColor(4); }

    static jt::Color PaletteFontFront() { return GP::getPalette().getColor(0); }

    static jt::Color PalleteFrontHighlight() { return GP::getPalette().getColor(1); }

    static jt::Color PaletteFontShadow() { return GP::getPalette().getColor(2); }

    static jt::Color PaletteFontCredits() { return GP::getPalette().getColor(1); }

    static jt::Palette getPalette();

    static int PhysicVelocityIterations();
    static int PhysicPositionIterations();
    static jt::Vector2f PlayerSize();

    static float PlayerMoveStrength();
    static float PlayerTurnAngleInDegree();
    static float PlayerLinearDamping();
};

#endif
