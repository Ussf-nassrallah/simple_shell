#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void initialize_shell(void);
char *_get_env(const char *env);
char **divider(char *input);
char *_get_command(char *command);
int _strlen(char *s);

#endif
