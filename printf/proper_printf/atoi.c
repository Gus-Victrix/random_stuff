#include "main.h"
#include <stdlib.h>
/**
 * _atoi - Checks for a digit characters
 *
 * @str: string parameter
 *
 * Return: Digit characters found in string
 */
int _atoi(char *str)
{
	int i = 0;
	int newNum = 0;
	int signNum = 1;

	if (str[0] == '-')
	{
		signNum = -1;
		i++;
	}

	for (; str[i] != '\0'; ++i)
		newNum = newNum * 10 + str[i] - '0';
	return (signNum * newNum);
}
