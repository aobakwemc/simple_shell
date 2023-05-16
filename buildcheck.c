#include "c_shell.h"

/**
 * checkbuild - check if command is a built-in
 * @arv: array of arguments
 * Return: pointer to function taking arv & returns void
 */
void(*checkbuild(char **arv))(char **arv)
{
	int i, j;
	buildsetup T[] = {
		{"exit", exitshell},
		{"env", env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (i = 0; T[i].name; i++)
	{
		j = 0;
		if (T[i].name[j] == arv[0][j])
		{
			for (j = 0; arv[0][j]; j++)
			{
				if (T[i].name[j] != arv[0][j])
					break;
			}
			if (!arv[0][j])
				return (T[i].function);
		}
	}
	return (0);
}
