#include "main.h"

/**
 * _truncate - Truncate information on the buffer to meet precision requirement
 *
 * @possition: Posiiton of from which truncation count begins.
 * @precision: The number of allowed characters
 * @index: Pointer to current position of buffer.
 * @buffer: Buffer being dealt with.
 */

void _truncate(unsigned short position, int precision, unsigned short *index,
		char *buffer)
{
	short i = 0;

	i = *index - position;

	if (i <= precision)
		return;
	
	for (; i > precision; i--)
		(*index)--;
}

/**
 * _buffseek - Seek a character on a buffer.
 *
 * @buffer: The buffer in question.
 * @position: Position from which to search.
 * @index: Maximum position of search.
 * @c: Character to be found.
 *
 * Return: Index of the character being searched for in the buffer.
 */

unsigned short _buffseek(char *buffer, unsigned short position, unsigned short
		*index, char c)
{
	short i;

	for (i = position; i < *index; i++)
		if (buffer[i] == c)
			return (i);
}
