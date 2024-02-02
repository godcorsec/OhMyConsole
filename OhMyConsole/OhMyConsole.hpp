#include <iostream>
#include "Colour.h"
#include "Time.h"
#include "String.h"
#include <Windows.h>
#include "Extras/Messages.h"
#include "OhMyConfiguration.hpp"

// start-globals

std::string _title = "";



// end-globals

class OhMyConsole
{
private:

    void CreateConsole()
    {
        /*
        * If Inside Of A DLL, This Will Create A Console.
        */
        FILE* file;
        AllocConsole();

        freopen_s(&file, "CONOUT$", "w", stdout);
        freopen_s(&file, "CONIN$", "r", stdin);
        // end-console
    }

    void ClearConsole()
    {
        system("cls");
    }

    bool DoesConsoleExist()
    {
        HWND consoleWindow = GetConsoleWindow();
        if (!consoleWindow)
            return false;
        return true;
    }

public:
    OhMyConsole(OhMyConfiguation& config) : config(config) {}

    template<typename T, typename... Args>
    void print_ok(T first, Args... args)
    {
        if (config.get_update_strftime_status())
            NewConsoleTitle(_title.c_str());
        RGB Color = GetColor();
        std::cout << White << "[" << "\x1b[38;2;" << Color.R << ";" << Color.G << ";" << Color.B << "m" << GetTime22() << White << "] " << Lime;


        std::cout << first << ' ';
        (std::cout << ... << args) << std::endl;
    }



    template<typename T, typename... Args>
    void print_error(T first, Args... args)
    {
        if (config.get_update_strftime_status())
            NewConsoleTitle(_title.c_str());
        RGB Color = GetColor();
        std::cout << White << "[" << "\x1b[38;2;" << Color.R << ";" << Color.G << ";" << Color.B << "m" << GetTime22() << White << "] " << Red;



        std::cout << first << ' ';
        (std::cout << ... << args) << std::endl;
    }

    template<typename T, typename... Args>
    void print_info(T first, Args... args)
    {
        if (config.get_update_strftime_status())
            NewConsoleTitle(_title.c_str());
        RGB Color = GetColor();
        std::cout << White << "[" << "\x1b[38;2;" << Color.R << ";" << Color.G << ";" << Color.B << "m" << GetTime22() << White << "] " << Cyan;

        std::cout << first << ' ';
        (std::cout << ... << args) << std::endl;
    }

    template<typename T, typename... Args>
    void print_warn(T first, Args... args)
    {
        if (config.get_update_strftime_status())
            NewConsoleTitle(_title.c_str());
        RGB Color = GetColor();
        std::cout << White << "[" << "\x1b[38;2;" << Color.R << ";" << Color.G << ";" << Color.B << "m" << GetTime22() << White << "] " << Yellow;

        std::cout << first << ' ';
        (std::cout << ... << args) << std::endl;
    }



    void print_rainbow_string(std::string message)
    {
        if (config.get_update_strftime_status())
            NewConsoleTitle(_title.c_str());

        int offset = COLOR_PROPERTIES::COLOR_OFFSET;
        COLOR_PROPERTIES::COLOR_OFFSET = 1;
        for (const char c : message)
        {
            RGB Color = GetColor();
            std::cout << "\x1b[38;2;" << Color.R << ";" << Color.G << ";" << Color.B << "m" << c;

        }

        std::cout << "\n";
        COLOR_PROPERTIES::COLOR_OFFSET = offset;
    }


    void NewConsoleTitle(const char* title)
    {
        std::string titleStr(title);
        _title = titleStr; // save the provided title, so if `enable_strftime_update` is called, we can reformat and apply.

        // Replace With GetTime22()
        std::string FormatTime = "%FTT";

        // Replace With >:]
        std::string SmileyFace_w_Arrow = "%FSWA";

        // Replace With :]
        std::string SmileyFace_regular = "%FSR";

        String* string = new String();

        string->ReplaceSubstring(titleStr, FormatTime, GetTime22());
        string->ReplaceSubstring(titleStr, SmileyFace_w_Arrow, ">:]");
        string->ReplaceSubstring(titleStr, SmileyFace_regular, ":]");

        SetConsoleTitleA(titleStr.c_str());
    }


    void init()
    {
        set_config_vals_ext();
        CreateConsole();
        
        if (!config.get_silent_start_status())
        {
            Timer* timer = new Timer();
            timer->start();
            print_ok("Started", config.get_project_name().empty() ? "Instance" : config.get_project_name()); // if project_name() is empty, print "Started Instance" instead of empty: "Started <empty>"
            print_ok("Configuration Loaded");
            timer->end();
            print_ok("Finished In: ", timer->elapsed_to_str());
        }
    }

private:
    OhMyConfiguation config;
};