#ifndef ISURFACE_H
#define ISURFACE_H
#ifdef _WIN32
#pragma once
#endif

class isurface
{
public:

	void draw_set_color(color col)
	{
		using original_fn = void(__thiscall*)(PVOID, color);
		u::call_vfunc<original_fn>(this, 10)(this, col);
	}

	void draw_filled_rect(int x0, int y0, int x1, int y1)
	{
		using original_fn = void(__thiscall*)(PVOID, int, int, int, int);
		u::call_vfunc<original_fn>(this, 12)(this, x0, y0, x1, y1);
	}

	void draw_outlined_rect(int x0, int y0, int x1, int y1)
	{
		using original_fn = void(__thiscall*)(PVOID, int, int, int, int);
		u::call_vfunc<original_fn>(this, 14)(this, x0, y0, x1, y1);
	}

	void draw_line(int x0, int y0, int x1, int y1)
	{
		using original_fn = void(__thiscall*)(PVOID, int, int, int, int);
		u::call_vfunc<original_fn>(this, 15)(this, x0, y0, x1, y1);
	}

	void draw_set_text_font(unsigned long font)
	{
		using original_fn = void(__thiscall*)(PVOID, unsigned long);
		u::call_vfunc<original_fn>(this, 17)(this, font);
	}

	void draw_set_text_color(int r, int g, int b, int a)
	{
		using original_fn = void(__thiscall*)(PVOID, int, int, int, int);
		u::call_vfunc<original_fn>(this, 19)(this, r, g, b, a);
	}

	void draw_set_text_pos(int x, int y)
	{
		using original_fn = void(__thiscall*)(PVOID, int, int);
		u::call_vfunc<original_fn>(this, 20)(this, x, y);
	}

	void draw_print_text(const wchar_t* text, int text_length)
	{
		using original_fn = void(__thiscall*)(PVOID, const wchar_t*, int, int);
		u::call_vfunc<original_fn>(this, 22)(this, text, text_length, 0);
	}

	unsigned long create_font()
	{
		using original_fn = unsigned long(__thiscall*)(PVOID);
		return u::call_vfunc<original_fn>(this, 66)(this);
	}

	void set_font_glyph_set(unsigned long& font, const char* windows_font_name, int tall, int weight, int blur, int scanlines, int flags)
	{
		using original_fn = void(__thiscall*)(PVOID, unsigned long, const char*, int, int, int, int, int, int, int);
		u::call_vfunc<original_fn>(this, 67)(this, font, windows_font_name, tall, weight, blur, scanlines, flags, 0, 0);
	}

	bool get_text_size(unsigned long font, const wchar_t* text, int& width, int& tall)
	{
		using original_fn = bool(__thiscall*)(PVOID, unsigned long, const wchar_t*, int&, int&);
		return u::call_vfunc<original_fn>(this, 75)(this, font, text, width, tall);
	}

};

#endif // !ISURFACE_H