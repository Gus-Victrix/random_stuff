#include "main.h"

/**
 * show_non_print - Shows non printing characters in a string.
 *
 * @string: Input string.
 *
 * Return: Converted string.
 */

char *show_non_print(char *string)
{	
	char *s, *arr;
	short i = 0, k = 0;

	s = string;

	while (*s)
		 if (*s < 32 || *s > 126)
			 i++;
	if (i > 1)
	{
		s = malloc(sizeof(char) *(_strlen(string) + 4 * i + 1));
		i = 0;
		arr = malloc(sizeof(char) * 3);

		do {
			if (*string < 32 || *string > 126)
			{
				s[i++] = '\\';
				s[i++] = 'x';
				arr = from_int(*string, 16);
				while (arr[k])
					s[i++] = arr[k++];
			}
			s[i] = *string;
			string++, i++;
		} while (*string);
		string = s;
	}
	return (string);
}
