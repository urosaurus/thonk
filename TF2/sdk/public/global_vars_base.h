#ifndef GLOBAL_VARS_BASE_H
#define GLOBAL_VARS_BASE_H
#ifdef _WIN32
#pragma once
#endif

class global_vars_base
{
public:
	float	realtime;
	int		framecount;
	float	absoluteframetime;
	float	curtime;
	float	frametime;
	int		maxclients;
	int		tickcount;
	float	interval_per_tick;
	float	interpolation_amount;
};

#endif // !GLOBAL_VARS_BASE_H