#include "main.h"

/**
 * _change_dir - function that change dir
 * @command: represent destination (file name)
 * Return: Nothing
 */
void _change_dir(char *command)
{
	char str[100];

	if (command == NULL)
	{
		/* printing current working directory */
		printf("%s\n", getcwd(str, 100));
		/* change dir */
		chdir("/");
		/* printing current working directory */
		printf("%s\n", getcwd(str, 100));
	}
	else
	{
		/* printing current working directory */
		printf("%s\n", getcwd(str, 100));
		/* change dir */
		chdir(command);
		/* printing current working directory */
		printf("%s\n", getcwd(str, 100));
	}
}
