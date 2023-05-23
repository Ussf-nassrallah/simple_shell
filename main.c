#include "main.h"

/**
 * main - the starting point for program execution
 * @argc: number of arguments
 * @argv: array of arguments
 * @env: environment variables
 * Return: Always 0
 */

int main(int argc, char *argv[], char **env)
{
	char *prompt = "($): ";
	char *command_line;
	size_t len = 0;
	ssize_t read;
	char **arguments;
	(void)argc;
	(void)argv;

	initialize_shell();

	while (true)
	{
		printf("%s", prompt);
		read = getline(&command_line, &len, stdin);

		if (read == -1)
		{
			printf("exit\n");
			return (false);
		}
		arguments = divider(command_line);

		if (_strcmp(arguments[0], "exit") == 0)
		{
			exit(0);
		}
		else if (_strcmp(arguments[0], "cd") == 0)
		{
			_change_dir(arguments[1]);
			printf("change dir success\n");
		}
		else
		{
			execArguments(arguments, env);
		}
		free(command_line);
		command_line = NULL;
	}

	return (0);
}
