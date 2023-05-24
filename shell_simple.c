#include "main.h"

int main ()
{
        char prompt[] = "$ ";
        char *command[100], *dlm = "\n";
        char *argv[100], *token;
        size_t size = 100;
        int status, d;
	pid_t pid;

        while(1)
        {
		write(1, prompt, 2);
                d = getline(command, &size, stdin);
                if(d == -1)
                {
                        printf("\n");
                        break;
                }

                token = strtok(*command, dlm);
                argv[0] = token;
                argv[1] = NULL;
                pid = fork();
                if (pid == -1) {
                        perror("fork");
                        exit(EXIT_FAILURE);
                } else if (pid == 0) {
                        int ret = execve(argv[0], argv, NULL);
                        if (ret == -1) {
                                perror("./shell");
                                exit(EXIT_FAILURE);
                        }
                } else {
                        waitpid(pid, &status, 0);
                }
        }

        return (0);
}
