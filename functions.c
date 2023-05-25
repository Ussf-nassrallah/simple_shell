#include "main.h"

/**
 * divider - function that split string to slices
 * @input: string will be split
 * Return: array of slices
 */
char **divider(char *input)
{
    char **output;
    const char *d = " \t\n";
    char *token = strtok(input, d);
    int index = 0;
    int size = 100;

    output = malloc(sizeof(char *) * size);

    while (token != NULL)
    {
        output[index] = token;
        token = strtok(NULL, d);
        index++;
    }
    output[index] = NULL;

    output = realloc(output, sizeof(char *) * (index + 1));

    return output;
}


/**
 * _get_env - search for env variables
 * @env: env variable
 * Return: return a pointer to the string containing the value
 */
char *_get_env(const char *env)
{
    int index = 0;
    char *slice;
    char *value = NULL;

    while (environ[index])
    {
        slice = strtok(environ[index], "=");
        if (_strcmp(env, slice) == 0)
        {
            value = strtok(NULL, "\n");
            break;
        }
        index++;
    }

    while (slice != NULL)
    {
        slice = strtok(NULL, "=");
    }

    return value;
}


/**
 * _get_command - function that get command
 * @command: command will be operated
 * Return: pointer (output: command program path)
 */
char *_get_command(char *command)
{
        char *path = _get_env("PATH");
        char *slice;
        char *output;
        struct stat st;

        slice = strtok(path, ":");
        while (slice)
        {
                output = malloc(_strlen(slice) + _strlen(command) + 2);
                _strcpy(output, slice);
                _strcat(output, "/");
                _strcat(output, command);
                if (stat(output, &st) == 0)
                        return (output);
                free(output);
                slice = strtok(NULL, ":");
        }

        return (NULL);
}
