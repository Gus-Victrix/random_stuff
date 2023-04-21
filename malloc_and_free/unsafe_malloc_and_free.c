
/**
 * This is an implementation of malloc() and free() in C for POSIX systems.
 * It has been built with systems that initialize heap automatically in mind.
 *
 * These versions of my_malloc() and my_free() are not safe to use since the
 *	size of the memory may be accidentally modified by it's user.
 *
 * Author: Gus-Victrix
 * Date: Apr 21st, 2023.
 */
#include <sys/mman.h>
#include <stddef.h>


/**
 * my_malloc - Used in allocation of memory from the heap.
 *
 * @size: Size of the memory to be allocated in bytes.
 *
 * Description: The function uses mmap() from sys/mman header file to allocate
 *				memory.
 * Return: Pointer to region of memory allocated in heap, Null if errors are
 *			encountered.
 */

void *my_malloc(size_t size)
{
	void *addr;
	size_t size_tracker;

	//Allocating memory from existing heap.
	addr = mmap(NULL, size + sizeof(size_t), PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
	
	if (addr == MAP_FAILED)
		return (NULL);
	//Entering the size of memory into the start of block for my_free.
	*(size_t *)addr = size;

	return ((void *)(addr + sizeof(size_t)));
}

/**
 * my_free - Used to de-allocate memory allocated in heap.
 *
 * @pointer: This is a pointer to the memory to be de-allocated.
 *
 * Description: Uses munmap to de-allocate memory allocated specifically using
 *				my_malloc.
 *				The function de-allocates memory by checking the size stored at
 *				the start of the memory block by my_malloc().
 */

void my_free(void *ptr)
{
	munmap((size_t *)ptr - 1, *((size_t *)ptr -1));
}
