#include "main.h"

/**
 * rot13 - encodes string using rot13
 * @s: string
 *
 * Return: encoded string
 */
char *rot13(char *s)
{
	char	*l = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char	*rot = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char	*p = s;
	int	i;

	while (*p)
	{
		i = 0;
		while (l[i])
		{
			if (l[i] == *p)
			{
				*p = rot[i];
				break;
			}
			i++;
		}
		p++;
	}
	return (s);
}
