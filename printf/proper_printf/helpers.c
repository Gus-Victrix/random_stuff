/**
 * These are the functions that are supposed to help in _printf functionalities.
 * They handle the specific cases of the simple format specifiers.
 * The more complex ones are going to be handled in a different file.
 */

#include "main.h"

/**
 * _percentile - Handles case where printf receives "%%".
 *
 * @format: This is the format string being printed by _printf.
 * @ptr: This is the current position being handled on format.
 * @buffer: The buffer used to store characters before printing.
 * @index: Current empty position on buffer.
 * @params: Variadic argument to be handled specially by this function.
 *
 * Return: Number of characters printed while function runs.
 */

int _percentile(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params)
{
	int i = *ptr;
	(*ptr)++;

	return (_push((char *)format + i, 1, index, buffer));
}

/**
 * _character - Handles case %c in _printf.
 *
 * @format: This is the format string being printed by _printf.
 * @ptr: This is the current position being handled on format.
 * @buffer: The buffer used to store characters before printing.
 * @index: Current empty position on buffer.
 * @params: Variadic argument to be handled specially by this function.
 *
 * Return: Number of characters printed while function runs.
 */

int _character(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params)
{
	char c;
	c = va_arg(params, int);
	(*ptr)++;
	return (_push(&c, 1, index, buffer));
}

/**
 * _string - Handles case %s in _printf.
 *
 * @format: This is the format string being printed by _printf.
 * @ptr: This is the current position being handled on format.
 * @buffer: The buffer used to store characters before printing.
 * @index: Current empty position on buffer.
 * @params: Variadic argument to be handled specially by this function.
 *
 * Return: Number of characters printed while function runs.
 */
int _string(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params)
{
	char *s;

	(*ptr)++;
	s = va_arg(params, char *);
	return (_push(s, _strlen(s), index, buffer));
}

/**
 * _integer - Handles case 'd' and 'i'.
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

	s = malloc(sizeof(char) * 2);
	s = "0x";
	i +=_push(s, 2, index, buffer);
	free(s);
	(*ptr)++;

	s = from_int(va_arg(params, int), 16);
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

	s = malloc(sizeof(char) * 2);
	s = "0X";
	i +=_push(s, 2, index, buffer);
	free(s);

	s = upper(from_int(va_arg(params, int), 16));
	i +=_push(s, _strlen(s), index, buffer);
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

	s = malloc(sizeof(char) * 2);
	s = "0b";
	i +=_push(s, 2, index, buffer);
	free(s);

	s = from_int(va_arg(params, int), 2);
	i +=_push(s, _strlen(s), index, buffer);
	free(s);
	(*ptr)++;
	return (i);
}