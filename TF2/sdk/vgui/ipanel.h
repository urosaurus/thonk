#ifndef IPANEL_H
#define IPANEL_H
#ifdef _WIN32
#pragma once
#endif

class ipanel
{
public:

	const char* get_name(unsigned int vgui_panel)
	{
		using original_fn = const char*(__thiscall*)(PVOID, unsigned int);
		return u::call_vfunc<original_fn>(this, 36)(this, vgui_panel);
	}

};

#endif // !IPANEL_H