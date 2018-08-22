#ifndef IVENGINECLIENT_H
#define IVENGINECLIENT_H
#ifdef _WIN32
#pragma once
#endif

typedef struct player_info_s
{

	char			name[32];
	int				user_id;
	char			guid[33];
	unsigned long	friends_id;
	char			friends_name[32];
	bool			fake_player;
	bool			ishltv;
	unsigned long	custom_files[4];
	unsigned char	files_downloaded;

} player_info_t;

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

	bool is_taking_screenshot()
	{
		using original_fn = bool(__thiscall*)(PVOID);
		return u::call_vfunc<original_fn>(this, 85)(this);
	}

	void set_view_angles(vector& ang)
	{
		using original_fn = void(__thiscall*)(PVOID, vector&);
		return u::call_vfunc<original_fn>(this, 20)(this, ang);
	}

	bool get_player_info(int i, player_info_t* info)
	{
		using original_fn = bool(__thiscall*)(PVOID, int, player_info_t*);
		return u::call_vfunc<original_fn>(this, 8)(this, i, info);
	}

};

#endif // !IVENGINECLIENT_H
