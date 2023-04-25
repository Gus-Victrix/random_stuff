#include "main.h"

/**
 * _address - Handles case 'p'.
 *
 * @format: This is the format string being printed by _printf.
 * @ptr: This is the current position being handled on format.
 * @buffer: The buffer used to store characters before printing.
 * @index: Current empty position on buffer.
 * @params: Variadic argument to be handled specially by this function.
 *
 * Return: Number of characters printed while function runs.
 */
int _address(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params)
{
	char *s;
	int i = 0;

	(*ptr)++;
	s = "0x";
	i += _push(s, 2, index, buffer);
	s = va_arg(params, void *);
	s = from_unsigned((long long)s, 16);
	i += _push(s, _strlen(s), index, buffer);
	return (i);
}
