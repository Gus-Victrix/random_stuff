#include "main.h"
/**
 * _special_padding - Handles Field size and justification for printf.
 *
 * @format: Formatted text passed from printf.
 * @ptr: Current position on format to be printed.
 * @buffer: Buffer holding characters ready to be printed.
 * @index: Index of next empty position on buffer.
 * @params: Pointer to next argument to printf.
 *
 * Return: Number of characters printed.
 */

int _special_padding(const char *format,int *ptr, char *buffer, unsigned short *index,
		va_list params)
{
	short i = 0;
	int (*func)(const char *, int *, char *, unsigned short *, va_list);
	int result = 0;

	i = *index;
	(*ptr)++;
	func = get_func(format, ptr);
	result += func(format, ptr, buffer, index, params);
	pad_mgr(buffer, index, i, 0, '0', 1);
	return (result);
}
