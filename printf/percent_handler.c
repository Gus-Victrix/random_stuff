#include "main.h"

/**
 * percent_handler - Handles case where current letter on format string is '%'.
 *
 * @format: The foramatted string being considered.
 * @pointer: Pointer to current index of format.
 * @buffer: Buffer containing the ready to print string.
 * @index: Pointer to current index of buffer.
 *
 * Return: Number of times buffer is flushed while the percent_handler runs.
 */

size_t percent_handler(const char *format, size_t *pointer, char *buffer, unsigned
		short *index, va_list params)
{
	size_t flushed = 0;
	char c, *rep;
	rep = &c;

	switch (format[*pointer +1])
	{
		case '%':
			*rep = '%';
			return (_push(rep, 1, index, buffer));
		case 'c':
			c = va_arg(params, char);
			return (_push(rep, 1, index, buffer));
		case 's':
			rep = va_arg(params, char *);
			return (_push(rep, _strlen(rep), index, buffer));
		case 'd':
			rep = int_to_string(va_arg(params, int));
			return (_push(rep, _strlen(rep), index, buffer));
		case 'b':
			rep = dec_to_bin(va_arg(params, int));
			return (_push(rep, _strlen(rep), index, buffer));
		case 'x':
			rep = dec_to_hex(va_arg(params, int));
			return (_push(rep, _strlen(rep), index, buffer));
		case 'X':
			rep = upper(ints_to_hex(int_to_string(va_arg(params, int))));
			return (_push(rep, _strlen(rep), index, buffer));
	}
	return (flushed);
}
