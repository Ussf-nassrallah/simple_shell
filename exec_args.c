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
            // Use exit_status to handle the exit status of the child process
            // For example, you can print it or use it for further processing
            if (exit_status != 0)
            {
                // Handle non-zero exit status
            }
        }
    }

    free(arguments);
}
