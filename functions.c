#include "main.h"

void print_arguments(char *arg[]);
void fork_example(void);
void split_str(char *s);
void execve_sys_call(void);

/**
 * print_arguments - funcion that prints all the arguments, without using ac
 * @arg: arguments will be printed
 * Return: Nothing
*/
void print_arguments(char *arg[])
{
	int index = 0;
	while (arg[index])
	{
		printf("%s\n", arg[index]);
		index++;
	}
}

void fork_example(void)
{
	char *s;
	int pid = getpid();
	int ppid = getppid();

	if (fork() == 0)
	{
		s = "hello from child!";
		printf("%s\tthe process id of child is : %d\n", s, pid);
	}
	else
	{
		s = "hello from parent!";
		printf("%s\tthe process id of parent is : %d\n", s, ppid);
	}
	// Write a shell script that prints the maximum value a process ID can be.
	// echo $((2**22-1)) => 4194303
}

void split_str(char *s)
{
    const char *delimiter = " ";
    char *slice = strtok(s, delimiter);

    while (slice != NULL)
    {
        printf("%s\n", slice);
        slice = strtok(NULL, delimiter);
    }
}

void execve_sys_call(void)
{
	char *path = "/bin/pwd";
	char *arg[] = {path, NULL};
	char *env[] = {NULL};
	int ouput = execve(path, arg, env);

	printf("Start of execve call %s\n", path);
	if (ouput == -1)
		perror("could not exe execve");

	printf("oops, something went wrong!");
}

/**
 * main - the starting point for program execution
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: Always 0
*/
int main(int argc, char *argv[])
{
	char string[] = "hello world my friend";
	(void)argc;
	// print_arguments(argv);
	// fork_example();
	// split_str(string);
	execve_sys_call();
	return (0);
}