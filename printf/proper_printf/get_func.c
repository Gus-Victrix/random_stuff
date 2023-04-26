#include "main.h"

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
	  {'o', _octal},
	  {'b', _binary},
	  {'S', _special_string},
	  {'r', _reverse},
	  {'R', _rot13},
	  {'p', _address},
	  {'u', _unsinged},
	  {'l', _long},
	  {'h', _short},
	  {'0', _special_padding},
	  {0, _padding}
  };
  unsigned short i = 0;

  while (function[i].f)
  {
	  if (function[i].c == *(format + *ptr))
		  break;
	  i++;
  }
  return (function[i].f);
}

/**
 * _padding - Handles Field size and justification for printf.
 *
 * @format: Formatted text passed from printf.
 * @ptr: Current position on format to be printed.
 * @buffer: Buffer holding characters ready to be printed.
 * @index: Index of next empty position on buffer.
 * @params: Pointer to next argument to printf.
 *
 * Return: Number of characters printed.
 */

int _padding(const char *format,int *ptr, char *buffer, unsigned short *index,
		va_list params)
{
	char c = ' ';
	short width = 0, i = 0, count;
	int (*func)(const char *, int *, char *, unsigned short *, va_list);
	int result = 0;

	c = *(format + *ptr);
	if (c >= '0' && c <= '9')
	{
		width = _atoi(format + *ptr);
		while (*(format + *ptr) >= '0' && *(format + *ptr) <= '9')
			(*ptr)++;
		i = *index;
		func = get_func(format, ptr);
		result += func(format, ptr, buffer, index, params);
		if (*index - i > width)
			pad_mgr(buffer, index, i, 0, ' ', width - (*index - i));
		return (result);
	}
	if (c == '+')
	{
		i = *index;
		(*ptr)++;
		func = get_func(format, ptr);
		result += func(format, ptr, buffer, index, params);
		if (buffer[i] != '-')
		{
			pad_mgr(buffer, index, i, 0, '+', 1);
			return (result);
		}
	}
	if (c == ' ')
	{

		i = *index;
		(*ptr)++;
		func = get_func(format, ptr);
		result += func(format, ptr, buffer, index, params);
		pad_mgr(buffer, index, i, 0, ' ', 1);
		return (result);
	}
	return (_push((char *)format + *ptr - 1, 2, index, buffer));
}

int _precision(const char *format,int *ptr, char *buffer, unsigned short *index,
		va_list params)
{
	int result = 0, precision;
	unsigned short i = 0;
	int (*func)(const char *, int *, char *, unsigned short *, va_list);

	*(ptr)++;
	if (*ptr >= '0' && *ptr <= '9')
		precision = _atoi((char *)format + *ptr);
	while (format[*ptr] >= '0' && *ptr <= '9')
	{
		(*ptr)++;
	}
	func = get_func(format, ptr);
	if (func != _float && func != _long && func != _short)
	{
		result = func(format, ptr, buffer, index, params);
		return (result);
	}
	i = *index;
	result += func(format, ptr, buffer, index, params);
	_truncate(_buffseek(buffer, i, index,'.'), precision, index, buffer);
	return (result);
}
