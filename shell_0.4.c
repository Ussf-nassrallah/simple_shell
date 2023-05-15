#include "main.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    char prompt[] = "#cisfun$ ";
    char *command[100];
    char *argv[100];
    size_t size = 100;
    int status;

    while (1)
    {
        printf("%s", prompt);
        if (getline(command, &size, stdin) == -1)
        {
            printf("\n");
            break;
        }
        int argc = 0;
        char *token = strtok(*command, " \t\n");
        while (token != NULL)
        {
	    if(strcmp(token,"exit") == 0)
	    {
		    exit(0);
	    }
            argv[argc++] = token;
            token = strtok(NULL, " \t\n");
        }
        argv[argc] = NULL;

        pid_t pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            int ret = execvp(argv[0], argv);
            if (ret == -1)
            {
                perror(argv[0]);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

