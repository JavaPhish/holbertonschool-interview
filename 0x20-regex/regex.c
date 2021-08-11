#include <stdio.h>
#include <stdlib.h>
#include "regex.h"

/**
 * regex_match - regex . and *
 * @str: The string
 * @pattern: the regex expression
 *
 * Return: 1 if that pattern matches the string
 */
int regex_match(char const *str, char const *pattern)
{
	const char *star = NULL;
	const char *scopy = str;

	while (*str)
	{

		if ((*pattern == '.') || (*pattern == *str))
		{
			str++;
			pattern++;
			continue;
		}

		if (*pattern == '*')
		{
			star = pattern++;
			scopy = str;
			continue;
		}

		if (star)
		{
			pattern = star++;
			str = ++scopy;
			continue;
		}

		return (0);
	}
	while (*pattern == '*')
		pattern++;

	return (!*pattern);
}
