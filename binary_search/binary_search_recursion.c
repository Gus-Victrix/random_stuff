/**
 * Author: Francis Nderitu (Gus-Victrix)
 * Description: This is an implementation of a function in C that performs a
 *				binary search on an input array.
 */

int *bin_search(int *start, int *end, int value);
/**
 * binary_search - Function that searches a sorted integer array for a
 *					particular value using binary search algorithm.
 *
 * @val: Integer to be searched for in the array.
 * @size: Size of the array to be searched.
 * @arr: Input array.
 *
 * Return: Address of the value being searched for.
 */

int *binary_search(int *arr, unsigned int size, int value)
{
	//Checking for valid inputs.
	if (!arr) // Checking if arr is a null pointer.
	{
		//printf("Invalid array input\n");
		return (0); // Returning NULL pointer.
	}
	if (!size)// Checking if size of the array is 0.
	{
		//printf("Size of array is 0! Searching this is impossible!\n");
		return (0); // Returning NULL pointer.
	}

	//Calling the helper function bin_search() to do the actual search.
	return (bin_search(arr, arr + size - 1, value));
}

/**
 * bin_search - Perform binary search with valid inputs.
 *
 * @start: Address of starting point of the array.
 * @end: End point of array to be searched.
 * @value: Integer to be searched.
 *
 * Return: Address of integer to be searched for, 0 if absent.
 */

int *bin_search(int *start, int *end, int value)
{
	int *mid = 0;
	static char check = 0;

	if (check)
		return (0);

	mid = end + (start - end) / 2; //Address of the value being compared.
	if (mid == end)
		check = 1;

	if (*mid == value) //Checking if value has been found.
		return (mid); //Returning address of the found value.

	if (*mid > value) //Checking if value is less than the one in mid.
		return (bin_search(start, mid, value)); //Repeat check for left half.

	if (*mid < value) //Checking if value is greater than one in mid.
		return (bin_search(mid, end, value)); //Repeat for right half.
}
