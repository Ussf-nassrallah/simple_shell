#include "main.h"

/**
 * main - the starting point for program execution
 *
 * Return: Always 0
 */
int main(void)
{
	char prompt[] = "#cisfun$ ";
	char *command[100], *argv[100], *token;
	size_t size = 100;
	int status, argc;
	pid_t pid;
	
	while (1)
	{
		printf("%s", prompt);
		if (getline(command, &size, stdin) == -1)
		{
			printf("\n");
			exit (EXIT_SUCCESS);
		}

		argc = 0;
		token = strtok(*command, " \t\n");
		while (token != NULL)
		{
			if (strcmp(token,"exit") == 0)
				exit (EXIT_SUCCESS);
			argv[argc++] = token;
			token = strtok(NULL, " \t\n");
		}
		argv[argc] = NULL;
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit (EXIT_SUCCESS);
		}
		else if (pid == 0)
		{
			int ret = execvp(argv[0], argv);
			if (ret == -1)
			{
				perror(argv[0]);
				exit(EXIT_SUCCESS);
			}
		}
		else
			waitpid(pid, &status, 0);
	}
	return 0;
}
