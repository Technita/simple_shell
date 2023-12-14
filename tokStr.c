#include "simp_sh.h"

/**
 * custom_Strtok - tokenize a str
 * @originalStr: str to be tookenized
 * @delimit: the delimiter
 * Return: on success returns a char point
 */

char *custom_Strtok(char *originalStr, const char *delimit)
{
	static char *nxt_tok;
	char *sh_tok = NULL;

	if (originalStr != NULL)
	{
		nxt_tok = originalStr;
	}

	if (nxt_tok == NULL || *nxt_tok == '\0')
	{
		return (NULL);
	}
	nxt_tok += sh_strspn(nxt_tok, delimit);

	if (*nxt_tok == '\0')
	{
		return (NULL);
	}
	sh_tok = nxt_tok;

	nxt_tok = sh_tok + sh_strcspn(sh_tok, delimit);

	if (*nxt_tok != '\0')
	{
		*nxt_tok = '\0';
		nxt_tok++;
	}
	return (sh_tok);
}
