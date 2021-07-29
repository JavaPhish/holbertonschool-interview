#include <stdio.h>
#include "holberton.h"

/**
 * wildcmp - Implement a wildcard
 * @s1: String to compare with s2
 * @s2: String to compare with s1
 *
 * Return: 1 if identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	/* Reached end of string, return 1 */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* Iterate string if characters match */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	/* We reached a wildcard in the string */
	if (*s2 == '*')
	{
		/* End of s1 but s2 is on wildcard, keep going (Edge case) */
		if (*s1 == '\0')
			return (wildcmp(s1, s2 + 1));

		/* If ether side returns 1 then there is a wildcard here, keey iterating */
		if (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1))
			return (1);
	}

	/* If we reached here, the strings are mismatched. */
	return (0);
}
