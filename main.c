#include "main.h"

void trimSpaces(char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    int i;

    while (isspace(str[start])) {
        start++;
    }

    while (end >= start && isspace(str[end])) {
        end--;
    }

    for (i = 0; i <= end - start; i++) {
        str[i] = str[start + i];
    }

    str[i] = '\0';
}

int main(void)
{
        char *command[100], *dlm = "\n";
        char *argv[100], *token;
        size_t size = 100;
        int status, d;
	pid_t pid;

        while(1)
        {
                d = getline(command, &size, stdin);
		trimSpaces(*command);
		if ((strlen(*command) - 2)  == 0)
			exit(EXIT_SUCCESS);
                if(d == -1)
                {
                        exit (EXIT_SUCCESS);
                }

                token = strtok(*command, dlm);
                argv[0] = token;
                argv[1] = NULL;
                pid = fork();
                if (pid == -1) {
                        perror("fork");
                        exit(EXIT_SUCCESS);
                } else if (pid == 0) {
                        int ret = execve(argv[0], argv, NULL);
                        if (ret == -1) {
                                perror("./shell");
                                exit(EXIT_SUCCESS);
                        }
                } else {
                        waitpid(pid, &status, 0);
                }
        }

        return (0);
}
