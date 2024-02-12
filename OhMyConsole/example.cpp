#include "omc.h"

omc_c* console;
omc_c* _console = new omc_c();

int main()
{
	console = new omc_c();
	omcf_t config;
	config.colour_rotation_offset = 6;
	config.starting_rotation_value = 225;
	config.console_title = "Hello World";

	Timer* timer = new Timer();

	_console->load_configuration(&config);

	for (int i = 0; i < 250; i++)
	{
		_console->success("Successfully MFH 0x0[*[redacted]]");
		timer->pause_for(10);
	}
}