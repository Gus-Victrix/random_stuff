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
			func = get_func(format, ptr);
			printed += func(format, ptr, buffer, index, params);
		}
		printed += _push((char *)format + pos, 1, index, buffer);
		pos++;
	}
	printed += _flush(buffer, index);
}

/**
 * get_func - Gets the address of the helper function to handle a case.
 *
 * @format: Format string being printed by _printf.
 * @ptr: Position of the string currently being considered.
 *
 * Return: Address of the required function.
 */

int (*get_func(const char *format, int *ptr))(const char *, int *, char *,
		unsigned short *, va_list)
{
	functions function[] = {
		{'%', _percentile},
		{'c', _character},
		{'s', _string},
		{'d', _integer},
		{'i', _integer},
		{'x', _hexadecimal},
		{'X', _upper_hexadecimal},
		{0,0}
	};
	unsigned short i = 0;

	*(ptr)++;
	while (function[i].f)
	{
		if (function[i].c == *(format + *ptr))
			break;
		i++;
	}
	return (function[i].f);
}

