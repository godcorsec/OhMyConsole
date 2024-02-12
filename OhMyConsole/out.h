#pragma once

#include <iostream>
#include "time.h"
#include "colour.h"
#include "config.h"
#include <Windows.h>

const char* white = "\x1b[38;2;255;255;255m";
const char* lime = "\x1b[38;2;0;255;0m";
const char* red = "\x1b[38;2;196;12;27m";
const char* cyan = "\x1b[38;2;3;215;252m";
const char* yellow = "\x1b[38;2;196;193;12m";

class omc_c
{
public:

    void create_dll_console() {
        FILE* file;
        AllocConsole();

        freopen_s(&file, "CONOUT$", "w", stdout);
        freopen_s(&file, "CONIN$", "r", stdin);
    }

    void clear_console() {
        system("cls");
    }

    void title(const char* title) {
        SetConsoleTitleA(title);
    }

    template<typename T, typename... Args>
    void info(T first, Args... args)
    {
        RGB Colour = GetColour();
        std::cout << white << "[" << "\x1b[38;2;" << Colour.R << ";" << Colour.G << ";" << Colour.B << "m" << GetTime() << white << "] [" << cyan << "INFO" << white << "] " << cyan << white;


        std::cout << first << ' ';
        (std::cout << ... << args) << white << std::endl;
    }

    template<typename T, typename... Args>
    void error(T first, Args... args)
    {
        RGB Colour = GetColour();
        std::cout << white << "[" << "\x1b[38;2;" << Colour.R << ";" << Colour.G << ";" << Colour.B << "m" << GetTime() << white << "] [" << red << "ERROR" << white << "] " << red << white;


        std::cout << first << ' ';
        (std::cout << ... << args) << white << std::endl;
    }

    template<typename T, typename... Args>
    void warn(T first, Args... args)
    {
        RGB Colour = GetColour();
        std::cout << white << "[" << "\x1b[38;2;" << Colour.R << ";" << Colour.G << ";" << Colour.B << "m" << GetTime() << white << "] [" << yellow << "WARN" << white << "] " << yellow << white;


        std::cout << first << ' ';
        (std::cout << ... << args) << white << std::endl;
    }

    template<typename T, typename... Args>
    void success(T first, Args... args)
    {
        RGB Colour = GetColour();
        std::cout << white << "[" << "\x1b[38;2;" << Colour.R << ";" << Colour.G << ";" << Colour.B << "m" << GetTime() << white << "] [" << lime << "OK" << white << "] " << lime << white;


        std::cout << first << ' ';
        (std::cout << ... << args) << white << std::endl;
    }

    void load_configuration(omcf_t* config) {
        colourProperties::colour_offset = config->colour_rotation_offset;
        colourProperties::start_offset = config->starting_rotation_value;
        title(config->console_title.c_str());

        colourProperties::re_initialize();
    }
};