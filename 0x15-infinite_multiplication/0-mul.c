#include <stdlib.h>
#include "holberton.h"


/**
 * main - yea
 * @argc: Number of arguments
 * @argv: Arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	/* argument error handling */
	if (argc != 3)
		error();

	/* Validate each argument if its only numbers */
	validate(argv[1]);
	validate(argv[2]);

	multiply(argv[1], argv[2]);

	return (0);
}

/**
 * multiply - multiplies two numbers repd as strings together
 * @s1: String 1
 * @s2: String 2
 *
 * Return: 1 on success
*/
void multiply(char *s1, char *s2)
{
	int *num_s1, *num_s2, loopi, temp, loopj, *ans;

	num_s1 = malloc(sizeof(int) * length(s1));
	num_s2 = malloc(sizeof(int) * length(s2));
	ans = malloc(sizeof(int) * (length(s1) + length(s2)));

	for (loopi = length(s1) - 1, loopj = 0; loopi >= 0; loopi--, loopj++)
		num_s1[loopj] = s1[loopi] - '0';
	for (loopi = length(s2) - 1, loopj = 0; loopi >= 0; loopi--, loopj++)
		num_s2[loopj] = s2[loopi] - '0';

	/* Cross multiply the buffers together into the answer */
	for (loopi = 0; loopi < length(s2); loopi++)
		for (loopj = 0; loopj < length(s1); loopj++)
			ans[loopi + loopj] += num_s2[loopi] * num_s1[loopj];

	/* carry values over 10 to next slot in array (carry values) */
	for (loopi = 0; loopi < length(s1) + length(s2); loopi++)
	{
		temp = ans[loopi] / 10;
		ans[loopi] = ans[loopi] % 10;
		ans[loopi + 1] = ans[loopi + 1] + temp;
	}

	/* Skip leading zeroes */
	for (loopi = length(s1) + length(s2); loopi >= 0; loopi--)
		if (ans[loopi] > 0)
			break;

	/* Print number array */
	for (; loopi >= 0; loopi--)
		_putchar(ans[loopi] + '0');
	_putchar('\n');

	free(num_s1);
	free(num_s2);
	free(ans);
}

/**
 * error - print error and exit
 */
void error(void)
{
	int loop = 0;
	char error[] = "Error\n";

	for (; loop < length(error); loop++)
		_putchar(error[loop]);

	exit(98);
}

/**
 * validate - validates a str
 * @str: The string to check
 *
 * Return: none
 */
void validate(char *str)
{
	int len = 0;

	if (str)
	{
		while (str[len] != '\0')
		{
			if (str[len] < '0' || str[len] > '9')
				error();

			len++;
		}
	}
}

/**
 * length - Length of array
 * @arr: The array
 *
 * Return: Int the length
 */
int length(char *arr)
{
	int len = 0;

	if (!arr)
		return (0);

	while (arr[len] != '\0')
		len++;

	return (len);
}
