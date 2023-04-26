#include "main.h"

/**
 * buff_shift - Shifts existing characters on buffer and updates their position
 *
 * @buffer: This is the buffer to undergo the shift.
 * @index: This is the next empty spot on the buffer.
 * @shiftwidth: This is the number of steps each character is to be moved.
 * @group_size: This is the number of characters to be moved.
 *
 * Return: Pointer to old position that was first moved.
 */

char *buff_shift(char *buffer, unsigned short *index, short shiftwidth,
		short group_size)
{
	short i = 0, j = 0;

	j = *index;
	
	i = *index - group_size;
	
	while (j != i)
	{
		buffer[j + shiftwidth] = buffer[j];
		j--;
	}
	*index += shiftwidth;

	return (buffer + j);
}

/**
 * buff_replace - Replace characters on buffer used by printf with padding.
 *
 * @mod_pos: This is a pointer to the position on buffer being modified.
 * @mod_width: This is the number of spaces after mod_pos to be modified.
 * @padding: This is the character to be used as padding.
 */

void buff_replace(char *mod_pos, short mod_width, char padding)
{
	short i = 0;

	while (i < mod_width)
	{
		*mod_pos = padding;
		mod_pos++;
		i++;
	}
}
