#include "../main.h"

struct menu_item_t
{

	std::string name;

	union {
		float*	m_float;
		int*	m_int;
		bool*	m_bool;
	};

	float	float_step;
	int		int_step;
	int		type;

	union {
		float	float_min;
		int		int_min;
	};

	union {
		float	float_max;
		int		int_max;
	};

}; menu_item_t items[120];

namespace menu
{

	int add_menu_entry(int i, std::string name, bool* value)
	{
		items[i].name = name;
		items[i].m_bool = value;
		items[i].type = 0;

		return (i + 1);
	}

	int add_menu_entry(int i, std::string name, int* value, int min, int max, int step)
	{
		items[i].name = name;
		items[i].m_int = value;
		items[i].int_min = min;
		items[i].int_max = max;
		items[i].int_step = step;
		items[i].type = 1;

		return (i + 1);
	}

	int add_menu_entry(int i, std::string name, float* value, float min, float max, float step)
	{
		items[i].name = name;
		items[i].m_float = value;
		items[i].float_min = min;
		items[i].float_max = max;
		items[i].float_step = step;
		items[i].type = 2;

		return (i + 1);
	}

	void insert_menu_items()
	{

		int i = 0;

		if (!vars::example::example_tab)
			i = add_menu_entry(i, "[+] Example Tab", &vars::example::example_tab);
		if (vars::example::example_tab) {

			i = add_menu_entry(i, "[-] Example Tab", &vars::example::example_tab);

			i = add_menu_entry(i, "- Example int", &vars::example::example_int, 0, 100, 10);
			i = add_menu_entry(i, "- Example float", &vars::example::example_float, 0.f, 100.f, 10.f);
			i = add_menu_entry(i, "- Example bool", &vars::example::example_bool);
		}

		vars::menu::total_items = i;

	}

	void draw_menu()
	{

		d::draw_string(vars::menu::menu_x, vars::menu::menu_y - 7, color(147, 112, 219), f::arial, "Cheat:");
		d::draw_string(vars::menu::menu_x - 10, vars::menu::menu_y + 2 + (vars::menu::font_size * vars::menu::current_pos) + 5, color(147, 112, 219), f::arial, ">");

		for (int i = 0; i < vars::menu::total_items; ++i) {

			if (!strncmp(items[i].name.c_str(), "[+]", 3) || !strncmp(items[i].name.c_str(), "[-]", 3)) {
				d::draw_string(vars::menu::menu_x, vars::menu::menu_y + 2 + (vars::menu::font_size * i) + 4, color(255, 255, 255, 255), f::arial, items[i].name.c_str());
			} else {
				switch (items[i].type) {
				case 0:
					d::draw_string(vars::menu::menu_x, vars::menu::menu_y + 2 + (vars::menu::font_size * i) + 4, color(255, 255, 255, 255), f::arial, items[i].name.c_str());
					d::draw_string(vars::menu::menu_x + 150, vars::menu::menu_y + 2 + (vars::menu::font_size * i) + 4, color(255, 255, 255, 255), f::arial, "%s", (*items[i].m_bool) ? "On" : "Off");
					break;
				case 1:
					d::draw_string(vars::menu::menu_x, vars::menu::menu_y + 2 + (vars::menu::font_size * i) + 4, color(255, 255, 255, 255), f::arial, items[i].name.c_str());
					d::draw_string(vars::menu::menu_x + 150, vars::menu::menu_y + 2 + (vars::menu::font_size * i) + 4, color(255, 255, 255, 255), f::arial, "%i", *items[i].m_int);
					break;
				case 2:
					d::draw_string(vars::menu::menu_x, vars::menu::menu_y + 2 + (vars::menu::font_size * i) + 4, color(255, 255, 255, 255), f::arial, items[i].name.c_str());
					d::draw_string(vars::menu::menu_x + 150, vars::menu::menu_y + 2 + (vars::menu::font_size * i) + 4, color(255, 255, 255, 255), f::arial, "%.2f", *items[i].m_float);
					break;
				default:
					break;
				}
			}

		}

	}

	int handle_input(int key_num)
	{

		if (key_num == 72) {
			vars::menu::menu_active = !vars::menu::menu_active;
		}

		if (vars::menu::menu_active) {

			if (key_num == 88) {

				if (vars::menu::current_pos > 0) {
					vars::menu::current_pos--;
				} else {
					vars::menu::current_pos = vars::menu::total_items - 1;
				}

				return 0;

			} else if (key_num == 90) {

				if (vars::menu::current_pos < vars::menu::total_items - 1) {
					vars::menu::current_pos++;
				} else {
					vars::menu::current_pos = 0;
				}

			} else if (key_num == 89) {

				switch (items[vars::menu::current_pos].type) {
				case 0:
					*items[vars::menu::current_pos].m_bool = !*items[vars::menu::current_pos].m_bool;
					break;
				case 1:
					*items[vars::menu::current_pos].m_int -= items[vars::menu::current_pos].int_step;
					if (*items[vars::menu::current_pos].m_int < items[vars::menu::current_pos].int_min)
						*items[vars::menu::current_pos].m_int = items[vars::menu::current_pos].int_max;
					break;
				case 2:
					*items[vars::menu::current_pos].m_float -= items[vars::menu::current_pos].float_step;
					if (*items[vars::menu::current_pos].m_float < items[vars::menu::current_pos].float_min)
						*items[vars::menu::current_pos].m_float = items[vars::menu::current_pos].float_max;
					break;
				default:
					break;
				}

			} else if (key_num == 91) {

				switch (items[vars::menu::current_pos].type) {
				case 0:
					*items[vars::menu::current_pos].m_bool = !*items[vars::menu::current_pos].m_bool;
					break;
				case 1:

					*items[vars::menu::current_pos].m_int += items[vars::menu::current_pos].int_step;

					if (*items[vars::menu::current_pos].m_int > items[vars::menu::current_pos].int_max) {
						*items[vars::menu::current_pos].m_int = items[vars::menu::current_pos].int_min;
					}

					break;

				case 2:

					*items[vars::menu::current_pos].m_float += items[vars::menu::current_pos].float_step;

					if (*items[vars::menu::current_pos].m_float > items[vars::menu::current_pos].float_max) {
						*items[vars::menu::current_pos].m_float = items[vars::menu::current_pos].float_min;
					}

					break;

				default:
					break;
				}

			}

		}

		return 0;

	}

}