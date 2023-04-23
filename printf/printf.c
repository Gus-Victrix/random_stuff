#include "main.h"

/**
 * _printf - Prints formatted text to stdout.
 *
 * @format: Formatted string to be printed.
 *
 * Return: -1 if error encountered, number of printed characters otherwise.
 */

int _printf(const char *format, ...)
{
	size_t a = 0, flushed, *pointer;
	unsigned short i = 0, *index;
	char c, *str, *rep, buffer[1024];
	int d;

	index = &i, rep = &c, pointer = &a;

	va_list params;

	va_start(params, format);

	while (format[a])
	{
		if (format[a] == '%')
		{
			flushed += percent_handler(format, pointer, buffer, index, params);
			a += 2;
			continue;
		}
		if (format[a] == 92)
		{
			flushed += backslash_handler(format, pointer, buffer, index, params);
			a += 2;
			continue;
			switch (*(format + 1))
			{
				case 92:
					c = 92;
					str = &c;
					flushed += _push(str, 1, index, buffer);
					a += 2;
					break;
				case 'n':
					c = 10;
					str = &c;
					flushed += _push(str, 1, index, buffer);
					a += 2;
					break;
				case 'b':
					c = 

			}
		}
		c = format[a];
		flushed += _push(rep, 1, index, buffer);
	}
	va_end(params);
	flushed += _flush(buffer, index);
	return (flushed);
}
