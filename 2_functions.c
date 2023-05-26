#include "main.h"

/**
 * trimSpaces - trimSpaces function
 * @str: string
 * Return: Nothing
 */
void trimSpaces(char *str)
{
	int start = 0;
	int end = strlen(str) - 1;
	int i;

	while (isspace(str[start]))
	{
		start++;
	}

	while (end >= start && isspace(str[end]))
	{
		end--;
	}

	for (i = 0; i <= end - start; i++)
	{
		str[i] = str[start + i];
	}

	str[i] = '\0';
}

/**
 * cFWS - containsForwardSlash func
 * @str: string
 * Return: 0 if success
 */
int cFWS(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '/')
		{
			return (1);
		}
	}
	return (0);
}
