#ifndef MENU_H
#define MENU_H
#ifdef _WIN32
#pragma once
#endif

namespace menu
{
	extern void	insert_menu_items();
	extern void	draw_menu();
	extern int	handle_input(int key_num);
}

#endif // !MENU_H