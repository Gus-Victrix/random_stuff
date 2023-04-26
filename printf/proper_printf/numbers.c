#include "main.h"

/**
 * _integer - Handles case 'i' and 'd'
 *
 * @format: This is the format string being printed by _printf.
 * @ptr: This is the current position being handled on format.
 * @buffer: The buffer used to store characters before printing.
 * @index: Current empty position on buffer.
 * @params: Variadic argument to be handled specially by this function.
 *
 * Return: Number of characters printed while function runs.
 */

int _integer(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params)
{
	char *s;
	int i;

	s = from_int(va_arg(params, int), 10);
	i =_push(s, _strlen(s), index, buffer);
	free(s);
	(*ptr)++;
	return (i);
}

/**
 * _unsigned - Handles case 'u'
 *
 * @format: This is the format string being printed by _printf.
 * @ptr: This is the current position being handled on format.
 * @buffer: The buffer used to store characters before printing.
 * @index: Current empty position on buffer.
 * @params: Variadic argument to be handled specially by this function.
 *
 * Return: Number of characters printed while function runs.
 */

int _unsinged(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params)
{
	char *s;
	int i;

	s = from_unsigned(va_arg(params, unsigned), 10);
	i =_push(s, _strlen(s), index, buffer);
	free(s);
	(*ptr)++;
	return (i);
}

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

/**
 * _hexadecimal - Handles case 'x'.
 *
 * @format: This is the format string being printed by _printf.
 * @ptr: This is the current position being handled on format.
 * @buffer: The buffer used to store characters before printing.
 * @index: Current empty position on buffer.
 * @params: Variadic argument to be handled specially by this function.
 *
 * Return: Number of characters printed while function runs.
 */

int _hexadecimal(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params)
{
	char *s;
	int i = 0;

	(*ptr)++;

	s = from_unsigned(va_arg(params, unsigned), 16);
	i +=_push(s, _strlen(s), index, buffer);
	free(s);
	return (i);
}

/**
 * _upper_hexadecimal - Handles case 'X'.
 *
 * @format: This is the format string being printed by _printf.
 * @ptr: This is the current position being handled on format.
 * @buffer: The buffer used to store characters before printing.
 * @index: Current empty position on buffer.
 * @params: Variadic argument to be handled specially by this function.
 *
 * Return: Number of characters printed while function runs.
 */
int _upper_hexadecimal(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params)
{
	char *s;
	int i = 0;

	s = upper(from_unsigned(va_arg(params, unsigned), 16));
	i +=_push(s, _strlen(s), index, buffer);
	free(s);
	(*ptr)++;
	return (i);
}

/**
 * _octal - Handles case 'o'.
 *
 * @format: This is the format string being printed by _printf.
 * @ptr: This is the current position being handled on format.
 * @buffer: The buffer used to store characters before printing.
 * @index: Current empty position on buffer.
 * @params: Variadic argument to be handled specially by this function.
 *
 * Return: Number of characters printed while function runs.
 */

int _octal(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params)
{
	char *s;
	int i = 0;

	s = from_unsigned(va_arg(params, unsigned), 8);
	i +=_push(s, _strlen(s), index, buffer);
	free(s);
	(*ptr)++;
	return (i);
}
