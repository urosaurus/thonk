#include "../../main.h"

namespace d
{

	void draw_outlined_rect(int x, int y, int w, int h, color col)
	{
		i::surface->draw_set_color(col);
		i::surface->draw_outlined_rect(x, y, x + w, y + h);
	}

	void draw_line(int x, int y, int x1, int y1, color col) {
		i::surface->draw_set_color(col);
		i::surface->draw_line(x, y, x1, y1);
	}

	void draw_filled_rect(int x, int y, int w, int h, color col)
	{
		i::surface->draw_set_color(col);
		i::surface->draw_filled_rect(x, y, x + w, y + h);
	}

	void draw_string(int x, int y, color col, unsigned long font, const char* text, ...)
	{

		if (text == NULL)
			return;

		va_list			va_alist;
		char			buffer[1024];
		wchar_t			string[1024];

		va_start(va_alist, text);
		_vsnprintf(buffer, sizeof(buffer), text, va_alist);
		va_end(va_alist);

		MultiByteToWideChar(CP_UTF8, 0, buffer, 256, string, 256);

		i::surface->draw_set_text_pos(x, y);
		i::surface->draw_set_text_font(font);
		i::surface->draw_set_text_color(col.r(), col.g(), col.b(), col.a());
		i::surface->draw_print_text(string, wcslen(string));

	}

	void draw_string_centered(int x, int y, color col, unsigned long font, const char* text, ...) {

		if (text == NULL)
			return;

		va_list		va_alist;
		char		buffer[1024];
		wchar_t		string[1024];
		int			w, h;

		va_start(va_alist, text);
		_vsnprintf(buffer, sizeof(buffer), text, va_alist);
		va_end(va_alist);

		MultiByteToWideChar(CP_UTF8, 0, buffer, 256, string, 256);

		i::surface->get_text_size(font, string, w, h);
		i::surface->draw_set_text_pos(x - w / 2, y - h / 2);
		i::surface->draw_set_text_font(font);
		i::surface->draw_set_text_color(col.r(), col.g(), col.b(), col.a());
		i::surface->draw_print_text(string, wcslen(string));

	}

}