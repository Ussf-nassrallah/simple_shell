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
    char *command_line = NULL;
    size_t len = 0;
    ssize_t read;
    char **arguments;
    (void)argc;
    (void)argv;
    
    while (true)
    {
        read = getline(&command_line, &len, stdin);
        trimSpaces(command_line);

        if (_strlen(command_line) == 0 || _strlen(command_line) == 1)
        {
            free(command_line);
            exit(EXIT_SUCCESS);
        }

        if (read == -1)
        {
            free(command_line);
            exit(EXIT_SUCCESS);
        }

        arguments = divider(command_line);

        if (_strcmp(arguments[0], "exit") == 0)
        {
            free(arguments);
            free(command_line);
            exit(EXIT_SUCCESS);
        }
        else if (_strcmp(arguments[0], "cd") == 0)
        {
            _change_dir(arguments[1]);
            free(arguments);
        }
        else
        {
            execArguments(arguments, env);
        }
    }

    return 0;
}
