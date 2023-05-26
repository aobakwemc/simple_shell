#include "shell.h"

/**
 * freemem - Frees a pointer and NULLs the address
 * @ptr: Address of pointer to free
 * Return: 1 if freed, else 0.
 */
int freemem(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

