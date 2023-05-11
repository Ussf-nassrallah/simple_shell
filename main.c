#include "main.h"

/**
 * main - the starting point for program execution
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: Always 0
*/
int main(int argc, char *argv[])
{
	/* Variables */
	char *prompt = "($): ";
	char *command_line;
	size_t len = 0;
	ssize_t read;
	/* void argc: (arguments count) & argv: (array of arguments) */
	(void)argc;
	(void)argv;
	/* infinite loop start when the program run */
	while (true)
	{
		/* Print Prompt */
		printf("%s", prompt);
		/* get return value from getline() */
		read = getline(&command_line, &len, stdin);
		/* check return value of getline() => if read == -1 */
		if (read == -1)
		{
			printf("exit\n");
			return (false);
		}
		/* print results (output) */
		printf("output : %s", command_line);
		/* free up allocated memory */
		free(command_line);
		/* solution : free(): double free detected in tcache 2*/
		command_line = NULL;
	}

	return (0);
}
