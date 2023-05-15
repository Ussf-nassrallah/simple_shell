#include "main.h"

int main ()
{
        char prompt[] = "#cisfun$ ";
        char *command[100], *dlm = "\n";
        char *argv[100];
        size_t size = 100;
        int status;

        while(1)
        {
                printf("%s", prompt);
		int d = getline(command, &size, stdin);
		if(d == -1)
		{
			printf("\n");
			break;
		}
		char *token = strtok(*command, dlm);
		argv[0] = token;
		argv[1] = NULL;
                pid_t pid = fork();
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

