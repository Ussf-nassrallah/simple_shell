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
                if(ret == -1)
                {
                        perror("./shell");
                        exit(EXIT_SUCCESS);
                }
                exit(EXIT_SUCCESS);
        }
        else
        {
                waitpid(pid, &status, 0);
        }
}
