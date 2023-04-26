#include "main.h"

/**
 * pad_mgr - Manages padding with alignment in mind for the _printf.
 *
 * @buffer: The buffer to store the characters before printing.
 * @initial: The point from which padding should be done.
 * @direction: Direction of padding (0 right side alignment(left side padding)
 *				and any non zero character for left align (right padding)
 * @padding: The character to be used for padding.
 * @pad_size: Size of the padding to be done to input.
 * 
 * Description: It's prefered that the input buffer be emptied before calling
 *				whatever function that necessiated the padding.
 *
 * Return: 0;
 */

void pad_mgr(char *buffer, unsigned short *index, unsigned short initial,
		char direction, char padding, unsigned short pad_size)
{
	short i = 0;

	if (!direction)
	{
		buff_replace(buff_shift(buffer, index, pad_size, *index - initial),
				pad_size, padding);
		return;
	}
	while (i < pad_size)
	{
		buffer[*index] = padding;
		(*index)++, i++;
	}
}
