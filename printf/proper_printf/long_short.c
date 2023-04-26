#include "main.h"

/**
 * _long - Handles case 'l'
 *
 * @format: Formated text.
 * @ptr: Position on formatted text.
 * @buffer: Buffer used for.
 * @index: Position of next empty spot on buffer.
 * @params: Parameters passed to printf.
 *
 * Return: Number of printed characters.
 */

int _long(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params)
{
	
	int (*func)(const char *, int *, char *, unsigned short *, va_list);

	(*ptr)++;
	func = get_func(format, ptr);
	return (func(format, ptr, buffer, index, params));
}

/**
 * _short - Handles case 'l'
 *
 * @format: Formated text.
 * @ptr: Position on formatted text.
 * @buffer: Buffer used for.
 * @index: Position of next empty spot on buffer.
 * @params: Parameters passed to printf.
 *
 * Return: Number of printed characters.
 */

int _short(const char *format, int *ptr, char *buffer, unsigned short *index, va_list params)
{
	
	int (*func)(const char *, int *, char *, unsigned short *, va_list);

	(*ptr)++;
	func = get_func(format, ptr);
	return (func(format, ptr, buffer, index, params));
}

