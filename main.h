#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

void initialize_shell(void);
void check_com(char *com);
char **divider(char *input);
void execArguments(char *arguments);

#endif
