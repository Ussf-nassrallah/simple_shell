#include "main.h"

/**
 * execArguments - function that execute arguments
 * @arguments: args will be exec
 * @env: env variables
 * Return: Nothing
 */
void execArguments(char **arguments, char **env)
{
	pid_t pid;
	char *command;
	int status;

	pid = fork();
	if (pid == 0)
	{
		command = _get_command(arguments[0]);
		if (command)
			execve(command, arguments, env);
		else
			printf("command not found!\n");
		exit(0);
	}
	else
	{
		wait(&status);
	}
}
