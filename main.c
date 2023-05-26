#include "main.h"

void _run(char *command_line, ssize_t read, char **env);

/**
 * _run - run function
 * @com: command_line
 * Return: Nothing
 */

void _run(char *command_line, ssize_t read, char **env)
{
	char **arguments;

	if (_strlen(command_line) == 0 || _strlen(command_line) == 1)
	{
		free(command_line);
		exit(EXIT_SUCCESS);
	}
	if (read == -1)
	{
		free(command_line);
		exit(EXIT_SUCCESS);
	}
	arguments = divider(command_line);
	if (_strcmp(arguments[0], "exit") == 0)
	{
		free(arguments);
		free(command_line);
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(arguments[0], "cd") == 0)
	{
		_change_dir(arguments[1]);
		free(arguments);
	}
	else if (_strcmp(arguments[0], "env") == 0)
	{
		_ptenv(arguments);
		free(arguments);
	}
	else
		execArguments(arguments, env);
}


/**
 * main - the starting point for program execution
 * @argc: number of arguments
 * @argv: array of arguments
 * @env: environment variables
 * Return: Always 0
 */
int main(int argc, char *argv[], char **env)
{
	char *command_line = NULL;
	size_t len = 0;
	ssize_t read;
	(void)argc;
	(void)argv;

	while (true)
	{
		read = getline(&command_line, &len, stdin);
		trimSpaces(command_line);
		_run(command_line, read, env);
	}
	return (0);
}
