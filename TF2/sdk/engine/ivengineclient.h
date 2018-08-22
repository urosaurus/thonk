#ifndef IVENGINECLIENT_H
#define IVENGINECLIENT_H
#ifdef _WIN32
#pragma once
#endif

class ivengineclient
{
public:

	int get_local_player()
	{
		using original_fn = int(__thiscall*)(PVOID);
		return u::call_vfunc<original_fn>(this, 12)(this);
	}

	bool is_in_game()
	{
		using original_fn = bool(__thiscall*)(PVOID);
		return u::call_vfunc<original_fn>(this, 26)(this);
	}

	bool is_connected()
	{
		using original_fn = bool(__thiscall*)(PVOID);
		return u::call_vfunc<original_fn>(this, 27)(this);
	}

};

#endif // !IVENGINECLIENT_H