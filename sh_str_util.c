#include "simp_sh.h"

/**
 * sh_strspn - the len of the initial char of the str
 * @sh_str: str to be analized
 * @comp_str: str containing char to be counted
 * Return: on sucess len of initial char counted containig only comp_str
 *
 * by: nita - E
*/
size_t sh_strspn(const char *sh_str, const char *comp_str)
{
	size_t _counter = 0;
	const char *tmp_str = sh_str;

	/*While the current character is in the comp_str string.*/
	while (tmp_str[_counter] && sh_strchr(comp_str, tmp_str[_counter]) != NULL)
	{
		_counter++;
	}

	return (_counter);
}


/**
 * sh_strchr - check for firdt ocurrence of sh_str.
 * @sh_str: str to be searched
 * @sh_ch: char found in sh_str
 * Return: pointer to first occurence of str
 * or NULL if sh_ch not found.
 *
 * by: nita - E
*/
char *sh_strchr(const char *sh_str, int sh_ch)
{
	int _counter = 0;

	while (sh_str[_counter] != '\0')
	{
		if (sh_str[_counter] == sh_ch)
		{
			return ((char *)sh_str); /*Casting const away for compatibility.*/
		}
		_counter++;
	}
	return (NULL);
}


/**
 * sh_strcspn - counts the length of forbidden chars
 * @sh_str: str to be analized.
 * @forbidden_chars: str cotaning chars to be avoided.
 * Return: len of initial chars not in forbidden chars'
 *
 * by: nita - E
*/
size_t sh_strcspn(const char *sh_str, const char *forbidden_chars)
{
	size_t _counter = 0;
	const char *tmp_str = sh_str;

	while (tmp_str[_counter] != '\0')
	{
		if (sh_strchr(forbidden_chars, tmp_str[_counter]) != NULL)
		{
			return (_counter);
		}
		_counter++;
	}

	return (_counter);
}
