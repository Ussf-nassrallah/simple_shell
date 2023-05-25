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
    int status;

    pid = fork();
    if (pid == 0)
    {
        int ret = execve(arguments[0], arguments, env);
        if (ret == -1)
        {
            perror("./shell");
            exit(2);
        }
        exit(EXIT_SUCCESS);
    }
    else if (pid > 0)
    {
        waitpid(pid, &status, 0);
    }

    free(arguments);
}
