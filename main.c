#include "main.h"

/**
 * main - the starting point for program execution
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	char *prompt = "#cisfun$ ";
	char *command_line = NULL;
	size_t len = 0;
	int read;
	char *slice;
	int status;
	int index = 0;
	char **output;
	pid_t pid;
	(void) argv;
	(void) argc;

	while (true)
	{
		write(1, prompt, _strlen(prompt));
		read = getline(&command_line, &len, stdin);
		output = malloc(sizeof(char *) * 1024);
		slice = strtok(command_line, " /t/n");

		if (read == -1)
		{
			_puts("exit");
			return (false);
		}

		while (slice)
		{
			output[index] = slice;
			slice = strtok(NULL, " /t/n");
			index++;
		}
		output[index] = NULL;

		pid = fork();

		if (pid == 0)
		{
			if (execve(output[0], output, NULL) == -1)
				perror("./shell");
		}
		else
			wait(&status);
		index = 0;
		free(output);
	}
}
