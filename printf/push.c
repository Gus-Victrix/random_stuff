#include "main.h"

/**
 * _push - Pushes input character string to a buffer.
 *
 * @str: Character string to be pushed.
 * @num: Number of characters in str to be pushed.
 * @buff: Buffer to receive character string.
 * @index: Index of empty spot in buffer.
 *
 * Return: Number of characters added to buffer.
 */

size_t _push(char *str, size_t num, unsigned short *index, char *buffer)
{
	size_t flushed = 0;
	unsigned short i = 0;

	while (i < num)
	{
		if (*index == 1024)
		{
			flushed += _flush(buffer, index);
		}
		buffer[*index] = str[i];
		i++; 
		*index += 1;
	}
	return (flushed);
}
