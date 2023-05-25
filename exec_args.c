#include "main.h"

/**
 * execArguments - function that execute arguments
 * @arguments: args will be exec
 * @env: env variables
 * Return: Nothing
 */
void execArguments(char **arguments, char **env)
{
    pid_t pid;
    int status,ret;
    char *command;

    pid = fork();
    if (pid == 0)
    {
        if(containsForwardSlash(arguments[0]) == 0)
        {
                command = _get_command(arguments[0]);
                ret = execve(command, arguments, env);
        }
        else
        {
                ret = execve(arguments[0], arguments, env);
        }

        if (ret == -1)
        {
            perror("./shell");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }
    else if (pid > 0)
    {
        waitpid(pid, &status, 0);

        if (WIFEXITED(status))
        {
            int exit_status = WEXITSTATUS(status);
            if (exit_status != 0)
            {
                exit(2);
            }
        }
    }

    free(arguments);
}
