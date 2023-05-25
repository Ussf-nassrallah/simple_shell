#include "main.h"

/**
 * _change_dir - function that change dir
 * @command: represent destination (file name)
 * Return: Nothing
 */
void _change_dir(char *command)
{
        if (command == NULL)
        {
                chdir("/");
        }
        else
        {
                /* change dir */
                if (chdir(command) != 0)
                        _puts("cd: No such file or directory");
        }
}
