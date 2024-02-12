<div align="center">

## OhMyConsole

* A C++ Header-Based "Library" Thrown Together For Quick Projects.
* Please Note That OhMyConsole, Is In No-Way Optimized For "High-Performance", Or Anything Like That, But It's still quite fast.
* OhMyConsole Has Basic Functionality And Basic Customization Features - But Hey! It Works.

## USAGE:

</div>

```cpp

#include "OhMyConsole/omc.h"

omc_c* console = new omc_c();
Timer* timer = new Timer();   // A small extra class for basic Timer utility functions, built into OMC. 


int main()
{
    omcf_t config;
    config.colour_rotation_offset  = 6;                  //  [int] Value to apply to each rotation
    config.starting_rotation_value = 225;               //   [int] Starting value of the rotation [int]/360.
    config.console_title           = "hello world!";    //   [str] Sets the console title.

    console->create_dll_console();                     // only needed if you're inside of a DLL.
    console->load_configuration(&config);              // this is NOT required, however if not called, it will use the default options.

    console->info(...);
    console->warn(...);
    console->error(...);
    console->success(...);

    timer->start();
    timer->end();
    timer->pause_for([int] milliseconds);         // this will pause the current thread for [int] ms.
    timer->elapsed();          // returns the elapsed time, only if `end()` was called.
    timer->elapsed_to_str();    // returns the elapsed time as a [string]
    

} 
```
