#pragma once

#include <iostream>
#include <Windows.h>
#include <cmath>

namespace COLOR_PROPERTIES
{
    int START_OFFSET_COLOR = 165;
    int COLOR_OFFSET = 5;
    float LAST_COLOR = START_OFFSET_COLOR;
    float HUE = LAST_COLOR;
    float SATURATION = 1.0f;
    float VALUE = 1.0f;
}


const char* White = "\x1b[38;2;255;255;255m";
const char* Lime = "\x1b[38;2;0;255;0m";
const char* Red = "\x1b[38;2;196;12;27m";
const char* Cyan = "\x1b[38;2;3;215;252m";
const char* Yellow = "\x1b[38;2;196;193;12m";

void NextColor()
{
    COLOR_PROPERTIES::LAST_COLOR += COLOR_PROPERTIES::COLOR_OFFSET;
    if (COLOR_PROPERTIES::LAST_COLOR > 360)
        COLOR_PROPERTIES::LAST_COLOR -= 360;
}

struct RGB {
    int R;
    int G;
    int B;
};

RGB HSV_TO_RGB(float H, float S, float V) {
    RGB result;

    float C = V * S;
    float X = C * (1 - std::abs(std::fmod(H / 60.0, 2) - 1));
    float m = V - C;

    if (H >= 0 && H < 60) {
        result.R = static_cast<int>((C + m) * 255);
        result.G = static_cast<int>((X + m) * 255);
        result.B = static_cast<int>(m * 255);
    }
    else if (H >= 60 && H < 120) {
        result.R = static_cast<int>((X + m) * 255);
        result.G = static_cast<int>((C + m) * 255);
        result.B = static_cast<int>(m * 255);
    }
    else if (H >= 120 && H < 180) {
        result.R = static_cast<int>(m * 255);
        result.G = static_cast<int>((C + m) * 255);
        result.B = static_cast<int>((X + m) * 255);
    }
    else if (H >= 180 && H < 240) {
        result.R = static_cast<int>(m * 255);
        result.G = static_cast<int>((X + m) * 255);
        result.B = static_cast<int>((C + m) * 255);
    }
    else if (H >= 240 && H < 300) {
        result.R = static_cast<int>((X + m) * 255);
        result.G = static_cast<int>(m * 255);
        result.B = static_cast<int>((C + m) * 255);
    }
    else {
        result.R = static_cast<int>((C + m) * 255);
        result.G = static_cast<int>(m * 255);
        result.B = static_cast<int>((X + m) * 255);
    }

    return result;
}

RGB GetColor()
{
    NextColor();
    COLOR_PROPERTIES::HUE = COLOR_PROPERTIES::LAST_COLOR;
    return HSV_TO_RGB(COLOR_PROPERTIES::HUE, COLOR_PROPERTIES::SATURATION, COLOR_PROPERTIES::VALUE);
}