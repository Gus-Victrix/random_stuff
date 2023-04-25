#include "main.h"

/**
 * _binary - Handles case 'b'.
 *
 * @format: This is the format string being printed by _printf.
 * @ptr: This is the current position being handled on format.
 * @buffer: The buffer used to store characters before printing.
 * @index: Current empty position on buffer.
 * @params: Variadic argument to be handled specially by this function.
 *
 * Return: Number of characters printed while function runs.
 */
int _binary(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params)
{
	char *s;
	int i = 0;

	s = "0b";
	i +=_push(s, 2, index, buffer);

	s = from_unsigned(va_arg(params, unsigned), 2);
	i +=_push(s, _strlen(s), index, buffer);
	free(s);
	(*ptr)++;
	return (i);
}

