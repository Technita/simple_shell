#include "simp_sh.h"

/**
 * token_shCommand - tokenize and execute a specified program
 * @pathName: name of program
 * @userInput: user input to be tokenized
 */

void token_shCommand(const char *userInput, char *pathName)
{
	const char *delimit = " \n";
	char *replica = dup_str(userInput), *sh_nxt_cmd = NULL;
	int _count = 0, j;
	char **tokens;

	if (replica == NULL)
	{
		perror("Memory alloction failed");
		return;
	}

	tokens = malloc(sizeof(char *) * 10);
	if (tokens == NULL)
	{
		perror("Memory allocation failed");
		free(replica);
		return;
	}

	sh_nxt_cmd = custom_Strtok(replica, delimit);


	while (sh_nxt_cmd != NULL && _count < 10)
	{
		tokens[_count] = dup_str(sh_nxt_cmd);
		_count++;
		sh_nxt_cmd = custom_Strtok(NULL, delimit);
	}

	if (_count > 0)
	{
		tokens[_count] = NULL;
		file_Exec(tokens[0], tokens, pathName);
		for (j = 0; j < _count; j++)
			free(tokens[j]);
	}

	free(tokens);
	free(replica);
}
