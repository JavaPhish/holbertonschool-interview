#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * is_palindrome - Determines if an unsigned integer is a palindrome
 * @n: The unsigned integer to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long temp = n;
	unsigned long reverse = 0;

	while (temp > 0)
	{
		reverse = reverse * 10 + temp % 10;
		temp = temp / 10;
	}

	if (n == reverse)
		return (1);
	return (0);
}
