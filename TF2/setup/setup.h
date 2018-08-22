#ifndef SETUP_H
#define SETUP_H
#ifdef _WIN32
#pragma once
#endif

namespace s
{
	extern void setup_interfaces();
	extern void setup_hooks();
	extern bool ready_to_blast();
}

#endif // !SETUP_H