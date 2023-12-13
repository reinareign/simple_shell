#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024

extern char **environ;

void display_prompt(void);
char **process_input(char *lineptr);
int handle_builtin_commands(char **argv);
int shell_loop(void);

void execmd(char **av);
char *find_path(char *cmd);
void arg(char *input, char ***av_ptr);

/** builtin commannds */
int exit_func(char *args[]);
int builtin_cd(char *args[]);
void env(void);

/** used functions */
int _putchar(char *c);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(char *str);
int length(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

#endif
