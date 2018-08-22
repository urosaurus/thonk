#ifndef IENGINEVGUI_H
#define IENGINEVGUI_H
#ifdef _WIN32
#pragma once
#endif

namespace vgui
{
	class panel;
};

enum vguipanel_t
{
	PANEL_ROOT = 0,
	PANEL_GAMEUIDLL,
	PANEL_CLIENTDLL,
	PANEL_TOOLS,
	PANEL_INGAMESCREENS,
	PANEL_GAMEDLL,
	PANEL_CLIENTDLL_TOOLS
};

enum paint_mode_t
{
	PAINT_UIPANELS		= (1 << 0),
	PAINT_INGAMEPANELS	= (1 << 1),
	PAINT_CURSOR		= (1 << 2),
};

class ienginevgui
{
public:
	virtual					~ienginevgui(void){}
	virtual unsigned long	get_panel(vguipanel_t type) = 0;
	virtual bool			is_game_ui_visible()		= 0;
};

#endif // !IENGINEVGUI_H