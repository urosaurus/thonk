#ifndef GLOBAL_H
#define GLOBAL_H
#ifdef _WIN32
#pragma once
#endif

namespace g
{
	extern c_baseentity*	local;
	extern user_cmd*		cmd;
	extern bool*		send_packet;
}

#endif // !GLOBAL_H
