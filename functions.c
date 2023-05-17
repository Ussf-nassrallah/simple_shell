#include "main.c"

/**
 * initialize_shell - Greeting shell during startup
 * Return: Nothing
 */
void initialize_shell(void)
{
	printf("\n\n\n\n******************************************");
	printf("\n\n\n\t**** SHELL PROJECT ****");
	printf("\n\n\t-Sometimes you have to break out of your shell to truly discover the world-\n\n");
	printf("\tDEVELOPERS :\n\n\t- Youssef Nassrallah\n\t- Redwan Ben Yechou\n");
	printf("\n\n\n\n******************************************");
	char *username = getenv("USER");

	printf("\n\n\nUSER is: @%s", username);
	printf("\n");
	sleep(1);
}

/**
 * check_com - check if the file or directory specified by path exists
 * @com: ele will be checked
 * Return: Nothing
 */
void check_com(char *com)
{
	if (access(com, F_OK) != 0)
		printf("NOT FOUND: %s\n", com);
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

	while (token != NULL)
	{
		output[index++] = token;
		check_com(token);
		token = strtok(NULL, d);
	}

	output[index] = NULL;
	return (output);
}

/**
 * execArguments - function that execut arguments
 * @arguments: args will be exec
 * Return: Nothing
 */
void execArguments(char *arguments)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		char **args = divider(arguments);

		if (execve(args[0], args, NULL) == -1)
			perror("ERROR");
		exit(0);
	}
	else
	{
		wait(NULL);
		return;
	}
}
