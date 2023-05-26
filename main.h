#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(const char *s1, char *s2);
char *_strcpy(char *dest, char *src);
void _puts(char *str);
int _putchar(char);

char *_get_env(const char *env);
char **divider(char *input);
char *_get_command(char *command);
void execArguments(char **arguments, char **env);
void _change_dir(char *command);
char *my_getline(void);
void trimSpaces(char *str);
int containsForwardSlash(const char* str);
char *_stokhelper(char *s, char *d);
char *_stok(char *s, char *d);

#endif
