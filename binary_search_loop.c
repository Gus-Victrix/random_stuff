/**
 * Author: Francis Nderitu (Gus-Victrix)
 * Description: This is an implementation of a function in C that performs a
 *				binary search on an input array using loops and switches.
 */

/**
 * binary_search - Function that searches a sorted integer array for a
 *					particular value using binary search algorithm.
 *
 * @value: Integer to be searched for in the array.
 * @size: Size of the array to be searched.
 * @start: Pointer to integer array to be searched.
 *
 * Return: Address of the value being searched for, NULL if issues encountered.
 */

int *binary_search(int *start, unsigned int size, int value)
{
	int *end = 0;
	int *mid = 0;
	char check = 0;

	if (!start)
		return (0);
	if (!size)
		return (0);

	end = start + size - 1;
	mid = start + (end - start) / 2;
	
	for (; !check;)
	{
		if (mid == start || mid == end)
			check = 1;
		switch ((char)(*mid != value))
		{
			case 1:
				switch ((char)(*mid < value))
				{
					case 1:
						mid = start + (mid - start) / 2;
						break;
					case 0:
						mid = mid + (end - mid) / 2;
						break;
				}
				break;
			case 0:
				return (mid);
		}
	}
	return (0);
}
