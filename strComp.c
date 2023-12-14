#include "simp_sh.h"

/**
 * _str_cmp - comps two str
 * @str_A: string A
 * @str_B: string B
 * Return: on success returns 1
 */

int _str_cmp(const char *str_A, const char *str_B)
{
	size_t i = 0;

	while (str_A[i] != '\0' && str_B[i] != '\0')
	{
		if (str_A[i] != str_B[i])
		{
			return ((int)(str_A[i] - str_B[i]));

		}
		i++;
	}
	if (str_A[i] == '\0' && str_B[i] == '\0')
	{
		return (0);
	}
	return ((int)(str_A[i] - str_B[i]));
}
