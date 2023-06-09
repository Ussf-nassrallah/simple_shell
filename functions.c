#include "main.h"

/**
 * divider - function that split string to slices
 * @input: string will be split
 * Return: array of slices
 */
char **divider(char *input)
{
	char **output;
	char *d = " \t\n";
	char *token = _stok(input, d);
	int index = 0;
	int size = 100;

	output = malloc(sizeof(char *) * size);

	while (token != NULL)
	{
		output[index] = token;
		token = _stok(NULL, d);
		index++;
	}
	output[index] = NULL;

	output = realloc(output, sizeof(char *) * (index + 1));

	return (output);
}


/**
 * _get_env - search for env variables
 * @env: env variable
 * Return: return a pointer to the string containing the value
 */
char *_get_env(const char *env)
{
	int index = 0;
	char *slice;
	char *value = NULL;

	while (environ[index])
	{
		slice = _stok(environ[index], "=");
		if (_strcmp(env, slice) == 0)
		{
			value = _stok(NULL, "\n");
			break;
		}
		index++;
	}

	while (slice != NULL)
	{
		slice = _stok(NULL, "=");
	}

	return (value);
}


/**
 * _get_command - function that get command
 * @command: command will be operated
 * Return: pointer (output: command program path)
 */
char *_get_command(char *command)
{
	char *path = _get_env("PATH");
	char *slice;
	char *output;
	struct stat st;

	slice = _stok(path, ":");
	while (slice)
	{
		output = malloc(_strlen(slice) + _strlen(command) + 2);
		_strcpy(output, slice);
		_strcat(output, "/");
		_strcat(output, command);
		if (stat(output, &st) == 0)
			return (output);
		free(output);
		slice = _stok(NULL, ":");
	}

	return (NULL);
}

/**
 * check_d - check if delim contain main character
 * @c: character will be operated
 * @d: separator
 * Return: 0 | 1
 */
int check_d(char c, char *d)
{
	int idx = 0;

	while (d[idx])
	{
		if (c == d[idx])
			return (1);
		idx++;
	}

	return (0);
}

/**
 * _stokhelper - go to the next slice
 * @s: string will be operated
 * @d: separator
 * Return: pointer or null
 */
char *_stokhelper(char *s, char *d)
{
	int index = 0;

	while (s[index])
	{
		if (check_d(s[index], d))
		{
			s[index] = '\0';

			while (check_d(s[index + 1], d))
			{
				s[index + 1] = '\0';
				index++;
			}

			if (s[index + 1] != '\0')
				return (&s[index + 1]);

			return (NULL);
		}

		index++;
	}

	return (NULL);
}
