#ifndef MAIN_H
#define MAIN_H
#include <signal.h>

void shell(char *src, char **env, sig_atomic_t *interrupted);
void sherror(char *src, char *str, char **strarr);
void strfree(char *str, char **strarr);
int _strcmp(char *s1, char *s2);
void strtrm(char *cmd);
char **cmd_args(char *cmd);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char **get_path(char *vari, char **env);
int path_handle(char **args, char **env);

#endif
