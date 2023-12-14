#include "simp_sh.h"

/**
 * exe_Disp - display a prompt
 * @shell_output: expected output to be displayed
 * Return: returns num if sucessful.
 */

int exe_Disp(char *shell_output)
{
	int char_len;

	/*count num of char to know len of str*/
	for (char_len = 0; shell_output[char_len] != '\0';)
	{
		char_len++;
	}

	/*write to stdout the num of str len*/
	write(1, shell_output, char_len);
	return (char_len);
}

/**
 * console_Print - outputs to stdout using putchar
 * @userInput: input of strings (vec_args)
 * Return: on success returns 0
 */

void console_Print(const char *userInput)
{
	size_t _len = 0;

	while (userInput[_len] != '\0')
	{
		_len++;
	}

	write(STDOUT_FILENO, userInput, _len);

}
