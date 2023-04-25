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

	(*ptr)++;
	while (function[i].f)
	{
		if (function[i].c == *(format + *ptr))
			break;
		i++;
	}
	return (function[i].f);
}


/**
 * _push - Pushes input character string to a buffer.
 *
 * @str: Character string to be pushed.
 * @num: Number of characters in str to be pushed.
 * @buff: Buffer to receive character string.
 * @index: Index of empty spot in buffer.
 *
 * Return: Number of characters added to buffer.
 */

int _push(char *str, int num, unsigned short *index, char *buffer)
{
	int flushed = 0;
	unsigned short i = 0;

	while (i < num)
	{
		if (*index == 1024)
		{
			flushed += _flush(buffer, index);
		}
		buffer[*index] = str[i];
		i++, (*index)++;
	}
	return (flushed);
}

/**
 * _flush - Flushes a buffer of specified size.
 *
 * @buffer: Character buffer to be flushed.
 * @index: Index to which the buffer is filled.
 *
 * Return: Number of printed characters.
 */

unsigned short _flush(char *buffer, unsigned short *index)
{
	unsigned short i = 0;

	i = *index;
	write(1, buffer, *index);
	*index = 0;

	return (i);
}
