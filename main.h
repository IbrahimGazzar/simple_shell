#ifndef MAIN_H
#define MAIN_H


void shell(char *src);
void sherror(char *src, char *str, char **strarr);
void strfree(char *str, char **strarr);
int _strcmp(char *s1, char *s2);
void strtrm(char *cmd);
char **cmd_args(char *cmd);
void shell(char*src);
void sherror(char *src, char *str);
int _strcmp(char *s1, char *s2);

#endif
