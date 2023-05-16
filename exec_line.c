#include "c_shell.h"

/**
 * stringsplit - takes a string & delimeter and returns array
 * of strigns as a result of splitting str via delimeter
 * @str: string to split
 * @delimeter: delimiter character
 * Return: array of pointers to words
 */

char **stringsplit(char *str, const char *delimeter)
{
	int i, wn;
	char **array;
	char *token;
	char *copy;

	copy = malloc(_strlen(str) + 1);
	if (copy == NULL)
	{
		perror(_getenv("_"));
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	token = strtok(copy, delimeter);
	array = malloc((sizeof(char *) * 2));
	array[0] = _strdup(token);
	i = 1;
	wn = 3;
	while (token)
	{
		token = strtok(NULL, delimeter);
		array = reallocation(array, (sizeof(char *) * (wn - 1)),
				(sizeof(char *) * wn));
		array[i] = _strdup(token);
		i++;
		wn++;
	}
	free(copy);
	return (array);
}

/**
 * execute - execute command
 * @av: array of terminal arguments
 */

void execute(char **av)
{
	int d, status;

	if (!av || !av[0])
		return;
	d = fork();
	if (d == -1)
	{
		perror(_getenv("_"));
	}
	if (d == 0)
	{
		execve(av[0], av, environ);
		perror(av[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}

/**
 * reallocation - reallocates new memory block
 * @ptr: previous pointer
 * @old_space: size of previous pointer
 * @new_space: size of new pointer that's allocated memory
 * Return: new pointer in new size
 */
void *reallocation(void *ptr, unsigned int old_space, unsigned int new_space)
{
	char *new;
	char *old;

	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_space));
	if (new_space == old_space)
		return (ptr);
	if (new_space == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	new = malloc(new_space);
	old = ptr;
	if (new == NULL)
		return (NULL);
	if (new_space > old_space)
	{
		for (i = 0; i < old_space; i++)
			new[i] = old[i];
		free(ptr);
		for (i = old_space; i < new_space; i++)
			new[i] = '\0';
	}
	if (new_space < old_space)
	{
		for (i = 0; i < new_space; i++)
			new[i] = old[i];
		free(ptr);
	}
	return (new);
}

/**
 * dealloc - frees array of pointers arv
 * @arv: array of pointers
 */
void dealloc(char **arv)
{
	int i;

	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
}
