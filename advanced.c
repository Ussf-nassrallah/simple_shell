#include "main.h"

static char *following;

/**
 * _stok - our strtok function that tokanize str
 * @s: string will be operated
 * @d: delimiter
 * Return: pointer or null
 */
char *_stok(char *s, char *d)
{
	/* check string */
	if (!s)
	{
		s = following;

		if (!s)
			return (NULL);
	}

	while (*s && *s == ' ')
		s++;

	following = _stokhelper(s, d);

	return (s);
}
