#include "simp_sh.h"

/**
 * main - S_Shell entry point
 * @vec_argc: counts the number of arguments (not used)
 * @vec_argv: the actual arguments
 * Return: on sucess returns 1
 */

int main(int vec_argc, char *vec_argv[])
{
	/*command name*/
	char *pathName = NULL;

	/*getline*/
	char *input_buff = NULL;
	size_t n = 0;

	pathName = vec_argv[0];
	(void)vec_argc;

	if (isatty(STDIN_FILENO))
	{

		while (1)
		{
			exe_Disp("$ ");
			/*taking user input*/
			input_buff = exec_getline(input_buff, &n);

			spec_str(input_buff, "exit\n", vec_argv);
			spec_str(input_buff, "env\n", vec_argv);

			token_shCommand(input_buff, pathName);
		}
		}
		else
		{
			while (getline(&input_buff, &n, stdin) != -1)
			{
				if (_str_cmp(input_buff, "exit\n") == 0)
				{
					free(input_buff);
					exit(0);
				}
				else
					token_shCommand(input_buff, pathName);
			}
		}
	free(input_buff);
	return (0);
}
