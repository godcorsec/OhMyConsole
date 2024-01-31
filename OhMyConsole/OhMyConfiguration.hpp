#include <string>
#include "Colour.h"


class OhMyConfiguation
{
private:
	std::string project_name = "";
	bool update_time_on_print = false;
	bool silent_start = false;
public:

	void enable_silent_start()
	{
		silent_start = true;
	}

	bool get_silent_start_status()
	{
		return silent_start;
	}

	void set_project_name(const char* value)
	{
		project_name = value;
	}

	std::string get_project_name()
	{
		return project_name;
	}

	void set_colour_start_rotation(int value)
	{
		COLOR_PROPERTIES::START_OFFSET_COLOR = value;
	}

	int get_colour_start_rotation()
	{
		return COLOR_PROPERTIES::START_OFFSET_COLOR;
	}

	void enable_update_strftime_title()
	{
		update_time_on_print = true;
	}

	void disable_update_strftime_title()
	{
		update_time_on_print = false;
	}

	bool get_update_strftime_status()
	{
		return update_time_on_print;
	}
};