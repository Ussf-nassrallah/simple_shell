#include "main.h"

/* ====== START: string_functions ====== */

/**
 * _strlen - function calculates the length of a given string
 * @s: string
 * Return: returns the length of string
 */
int _strlen(char *s)
{
	int index = 0;
	while (s[index] != '\0')
	{
		index++;
	}
	return (index);
}

/* ====== END: string_functions ====== */

/**
 * initialize_shell - Greeting shell during startup
 * Return: Nothing
 */
void initialize_shell(void)
{
	char *username = getenv("USER");

	printf("\n\n\n\n******************************************");
	printf("\n\n\n\t**** SHELL PROJECT ****");
	printf("\n\n\t-Sometimes you have to break out of your shell to truly discover the world-\n\n");
	printf("\tDEVELOPERS :\n\n\t- Youssef Nassrallah\n\t- Redwan Ben Yechou\n");
	printf("\n\n\n\n******************************************");
	printf("\n\n\nUSER is: @%s", username);
	printf("\n");
	sleep(1);
}

/**
 * divider - function that split string to slices
 * @input: string will be split
 * Return: array of slices
 */
char **divider(char *input)
{
	char **output;
	char *d = " \t\n";
	char *token = strtok(input, d);
	int index = 0;
	int size = 100;

	output = malloc(sizeof(char) * size);

	while (token != NULL)
	{
		output[index++] = token;
		token = strtok(NULL, d);

		if (index >= size)
		{
			size *= 2;
			output = realloc(output, sizeof(char *) * size);
		}
	}

	output[index] = NULL;
	return (output);
}

/**
 * _get_env - search for env variables
 * @env: env variable
 * Return: return a pointer to the string containing the value
*/
char *_get_env(const char *env)
{
	extern char **environ;
	int index = 0;
	char *slice;

	while (environ[index])
	{
		slice = strtok(environ[index], "=");
		if (strcmp(env, slice) == 0)
			return (strtok(NULL, "\n"));
		index++;
	}

	return (NULL);
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

	slice = strtok(path, ":");
	while (slice)
	{
		output = malloc(_strlen(slice) + _strlen(command) + 2);
		strcpy(output, slice);
		strcat(output, "/");
		strcat(output, command);
		if (stat(output, &st) == 0)
			return (output);
		free(output);
		slice = strtok(NULL, ":");
	}

	return (NULL);
}
