#include "main.h"

extern char **environ;

int main()
{
	char prompt[] = "($) ";
	char *command;
	char *argv[100];
	size_t size = 100;
	int status;

	while (1)
	{
		printf("%s", prompt);
		if ((command = _getline()) == NULL)
		{
			printf("\n");
			break;
		}
		int argc = 0;
		char *token = strtok(command, " \t\n");
		while (token != NULL)
		{
			if (strcmp(token, "exit") == 0)
			{
				exit(0);
			}
			else if (strcmp(token, "env") == 0)
			{
				char **env = environ;
				while (*env)
				{
					printf("%s\n", *env);
					env++;
				}
				break;
			}
			argv[argc++] = token;
			token = strtok(NULL, " \t\n");
		}
		argv[argc] = NULL;

		pid_t pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			int ret = execvp(argv[0], argv);
			if (ret == -1)
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}

	return 0;
}

