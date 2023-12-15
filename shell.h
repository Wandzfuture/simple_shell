#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFSIZE 1024
#define INIT_SIZE 100
#define EXP_FACTOR 4

extern char **environ;

void execute_cmd(char **command);

/*     errors     */
void handle_error(const char *msg);

/*     parsing    */
char **parse_cmd(char *line, char *err_msg);

/*     inputs     */
char *read_cmd();
char *my_getline(FILE *stream);

/* function declarations */
void fetch_env(char *env_name);

#endif
