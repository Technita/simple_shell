#include "simp_sh.h"

/**
 * handle_env - print environ var
 * @environVar: array of pointer (having the env var)
 */
void handle_env(char *const environVar[])
{
	int i = 0;

	while (environVar[i] != NULL)
	{
		console_Print(environVar[i]);
		console_Print("\n");
		i++;
	}
}


/**
 * exec_getline - exec the getline fnc
 * @input_buff: a place to store the user input
 * @n: size of expected input
 *
 * Return: the stored inout of the user
*/
char *exec_getline(char *input_buff, size_t *n)
{
	/*code to exec the getline when on interactive mode*/
	if (isatty(STDIN_FILENO))
	{
		if (getline(&input_buff, n, stdin) == -1)
		{
			free(input_buff);
			exit(0);
		}
	}
	return (input_buff);
}
