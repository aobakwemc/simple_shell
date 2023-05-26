#include "shell.h"

/**
 *  **_strncpy - It copies a string
 *   *@dest: For the destination string to be copied to
 *    *@src: The source string
 *     *@n: For the amount of characters to be copied
 *      *Return: The concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 *  **_strncat - It concatenates two strings
 *   *@dest: The first string
 *    *@src: The second string
 *     *@n: The amount of bytes to be maximally used
 *      *Return: The concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 *  **_strchr - To locates a character in a string
 *   *@d:Tthe string to be parsed
 *    *@f: The character to look for
 *     *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *d, char f)
{
	do {
		if (*d == f)
			return (d);
	} while (*d++ != '\0');

	return (NULL);
}

