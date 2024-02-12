#pragma once

#include <cmath>

typedef struct{

	int R;
	int G;
	int B;

} RGB;

namespace colourProperties{

	int colour_offset =          4;                //   This is how much to add to each colour per-rotation. 
	int start_offset  =          0;               //    Starting Colour Offset
	int last_colour   =          start_offset;    //     When getNextColour() is called, it will be called with last_colour first.
	float hue         =          start_offset;
	float saturation  =          1.0;
	float value       =          1.0;
    void re_initialize() {
        colour_offset = colour_offset;
        last_colour = start_offset;
    }
}

RGB hsv_to_rgb(float H, float S, float V) {
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

void NextColour()
{
    colourProperties::last_colour = colourProperties::last_colour + colourProperties::colour_offset;
    if (colourProperties::last_colour > 360)
        colourProperties::last_colour -= 360;
}

RGB GetColour()
{
    NextColour();
    colourProperties::hue = colourProperties::last_colour;
    return hsv_to_rgb(colourProperties::hue, colourProperties::saturation, colourProperties::value);
}