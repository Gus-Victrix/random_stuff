#include "main.h"

/**
 * backslash_handler - This function handles '\' in printf.
 *
 */

unsigned short backslash_handler(const char *format, size_t  *pointer, char *buffer, unsigned short *index, va_list params)
{
	size_t flushed = 0;
	char c, *rep;
	rep = &c;

	switch (format[*pointer + 1])
	{
		case 92:
			c = 92;
			return (_push(rep, 1, index, buffer));
		case 'a':
			c = 7;
			return (_push(rep, 1, index, buffer));
		case 'b':
			c = 8;
			return (_push(rep, 1, index, buffer));
		case 't':
			c = 9;
			return (_push(rep, 1, index, buffer));
		case 'r':
			c = 13;
			return (_push(rep, 1, index, buffer));
		case '%':
			c = '%';
			return (_push(rep, 1, index, buffer));
		case 34:
			c = 34;
			return (_push(rep, 1, index, buffer));
		case 39:
			c = 39;
			return (_push(rep, 1, index, buffer));
		case 'n':
			c = 10;
			return (_push(rep, 1, index, buffer));
		case 'f':
			c = 12;
			return (_push(rep, 1, index, buffer));
		case 'v':
			c  = 11;
			return (_push(rep, 1, index, buffer));
	}
}
