#include "main.h"
#include <ctype.h>

/**
 * main - a program that multiplies two positive numbers.
 * @argc: The argument count
 * @argv: The arguments
 *
 * Return: 0 on success, 38 otherwise
 */
int main(int argc, char *argv[])
{
	int mul[2000] = {0};
	int i, j;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = 0; i < 1024; i++)
		mul[i] = 0;
	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				printf("Error\n");
				exit(98);
			}
		}
	}
	_multiply(mul, argv);
	print_ans(mul);
	return (0);
}

/**
 * _strlen - This function returns the length of a string.
 * @s: The string to return the length
 *
 * Return: Length of s
 */
int _strlen(char *s)
{
	long int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * _multiply - multiply two numbers
 * @mul: The array to store the result
 * @str: The string
 *
 * Returns: void
 */
void _multiply(int *mul, char *str[])
{
	int i, j, len1, len2, tmp;
	char *s1 = str[1];
	char *s2 = str[2];

	rev_string(s1);
	rev_string(s2);

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	for (i = 0; i < len1; i++)
	{
		for (j = 0; j < len2; j++)
		{
			mul[i + j] += (s1[i] - '0') * (s2[j] - '0');
		}
	}

	for (i = 0; i < len1 + len2; i++)
	{
		tmp = mul[i] / 10;
		mul[i] = mul[i] % 10;
		mul[i + 1] = mul[i + 1] + tmp;
	}
}

/**
 * rev_string - This function reverses a string.
 * @s: the string to be reversed
 *
 * Return: void
 */
void rev_string(char *s)
{
	char tmp1, tmp2;
	int i, j;

	i = _strlen(s) - 1;
	j = 0;

	while (i != j && j < i)
	{
		tmp1 = s[i];
		tmp2 = s[j];
		s[i] = tmp2;
		s[j] = tmp1;
		j++;
		i--;
	}
}

/**
 * print_ans - Print the answer
 * @mul: the product
 *
 * Return: void
 */
void print_ans(int *mul)
{
	int i, isZero;

	isZero = 1;
	for (i = 1023; i >= 0; i--)
	{
		if (mul[i] > 0)
		{
			isZero = 0;
			break;
		}
	}
	for (; i >= 0; i--)
		printf("%d", mul[i]);
	if (isZero == 1)
		printf("0");
	printf("\n");
}
