#ifndef VARS_H
#define VARS_H
#ifdef _WIN32
#pragma once
#endif

namespace vars
{

	namespace menu
	{

		extern bool menu_active;

		extern int total_items;
		extern int current_pos;
		extern int font_size;
		extern int menu_x;
		extern int menu_y;

	}

	namespace example
	{

		extern int		example_int;
		extern float	example_float;
		extern bool		example_bool;
		extern bool		example_tab;

	}

}

#endif // !VARS_H