#include "main.h"

/**
 * _printf - Prints formatted text to stdout.
 *
 * @format: Formatted text input.
 *
 * Return: Number of printed characters.
 */

int _printf(const char *format, ...)
{
	int pos = 0, *ptr = &pos, printed = 0;
	unsigned short buffer_index = 0, *index = &buffer_index;
	char buffer[1024];
	int (*func)();
	va_list params;

	/*Checking if input string is empty*/
	if (!*format)
		return (-1);
	va_start(params, format);

	while (format[pos])
	{
		if (format[pos] == '%')
		{
			pos++;
			func = get_func(format, ptr);
			if (!func)
			{
				pos++;
				continue;
			}
			printed += func(format, ptr, buffer, index, params);
		}
		printed += _push((char *)format + pos, 1, index, buffer);
		pos++;
	}
	printed += _flush(buffer, index);
	return (printed);
}
