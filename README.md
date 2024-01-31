<div align="center">

## OhMyConsole

* A C++ Header-Based "Library" Thrown Together For Quick Projects.
* Please Note That OhMyConsole, Is In No-Way Optimized For "High-Performance", Or Anything Like That.
* OhMyConsole Has Basic Functionality And Basic Customization Features - But Hey! It Works.

## USAGE:

```cpp

#include "OhMyConsole/OhMyConsole.hpp"
#include "OhMyConsole/OhMyConfiguration.hpp"

int main()
{
    OhMyConfiguration* config = new OhMyConfiguration();
    config->set_project_name("NOT REQUIRED BUT LOOKS GOOD");
    config->set_colour_start_rotation(145); // this will make the color tags start at cyan. any number from 1-360 is valid. Anything Below / Higher Should Be Auto-Corrected.   ---> NOT REQUIRED.
    config->enable_update_strftime_title() // If you ever use `console->NewConsoleTitle("%FTT") // For A Custom STRFTIME, The Time Will Update With Every `print` call.        ----> NOT REQURIED, OFF BY DEFAULT.
    config->disable_update_strftime_title() // I mean, can you gues what this does?                                                                                            ----> NOT REQUIRED, THIS IS THE DEFAULT BOOLEAN STATE
    
    // config->get_abc123() is purely used for OhMyConsole, so it can set and use the values from the given configuration.
    
    OhMyConsole* console = new OhMyConsole(*config);  // I just love the look of console->abc123();
    console->init()  // initialize values from config, and just get the library ready.
    console->print_ok("This is a SUCCESS message and will be printed in Lime.");
    console->print_info("This is an INFO message and will be printed in Cyan. ");
    console->print_warn("This is a WARN message, and will be printed in Yellow. ");
    console->print_error("This is an ERROR message, and will be printed in Red. ");

    console->NewConsoleTitle("%FTT %FSWA %FSR");   // FTT = Formatted-Time,  FSWA = Formatted-Smiley-Face-With-Arrow: ">:)",  FSR = Formatted-Smiley-Face-Regular: ":)". 
}

```
