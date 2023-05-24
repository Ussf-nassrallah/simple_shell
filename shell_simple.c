#include "main.h"

/**
 * main - the starting point for program execution
 *
 * Return: Always 0
 */
int main(void)
{
	char prompt[] = "#cisfun$ ";
	char *command[100], *dlm = "\n";
	char *argv[100], *token;
	size_t size = 100;
	int status, d, ret;
	pid_t pid;

	while (1)
	{
		write(1, prompt, 9);
		d = getline(command, &size, stdin);
		if (d == -1)
		{
			perror("\n");
			break;
		}

		token = strtok(*command, dlm);
		argv[0] = token;
		argv[1] = NULL;
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		} else if (pid == 0)
		{
			ret = execve(argv[0], argv, NULL);
			if (ret == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		} else
			waitpid(pid, &status, 0);
	}
	return (0);
}
