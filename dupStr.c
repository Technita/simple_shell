#include "simp_sh.h"

/**
 * dup_str - creates a copy od original string
 * @originalStr: the original string ot copy from
 * Return: on success returns a char pointer
 */

char *dup_str(const char *originalStr)
{
	size_t len = 0;
	char *replica;
	size_t _count;

	while (originalStr[len] != '\0')
	{
		len++;
	}

	/*adding 1 for the '\0' char*/
	replica = malloc(len + 1);

	if (replica == NULL)
	{
		return (NULL);
	}

	for (_count = 0; _count <= len; _count++)
	{
		replica[_count] = originalStr[_count];
	}
	return (replica);
}


/**
 * spec_str - compare if chacker is env or exit
 * @buffer: the user's inout to check
 * @checker: wasnt used
 * @v_argv: the environment variable
*/
void spec_str(char *buffer, char *checker, char *v_argv[])
{
	/*code to check if user enters exit or env in input*/
	(void)checker;
	if (_str_cmp(buffer, "exit\n") == 0)
	{
		free(buffer);
		exit(0);
	}
	else if (_str_cmp(buffer, "env\n") == 0)
	{
		handle_env(v_argv);
	}
}
