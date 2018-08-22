#ifndef DRAW_H
#define DRAW_H
#ifdef _WIN32
#pragma once
#endif

namespace d
{
	extern void draw_outlined_rect(int x, int y, int w, int h, color col);
	extern void draw_line(int x, int y, int x1, int y1, color col);
	extern void draw_filled_rect(int x, int y, int w, int h, color col);
	extern void draw_string(int x, int y, color col, unsigned long font, const char* text, ...);
	extern void draw_string_centered(int x, int y, color col, unsigned long font, const char* text, ...);
}

#endif // !DRAW_H