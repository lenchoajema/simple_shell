#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

extern char **lenEnviron;
void len_puts(char *str);
int len_putchar(char c);
char *len_strdup(char *len_str);
char **len_handletok(char *len_buffer);
char *len_pathvalue(char **len_env);
char *len_pathch(char *len_token, char **len_env);
char *len_strstr(char *len_haystack, char *len_needle);
int lenStrcmp(char *lenS1, char *lenS2);
int lenStrncmp(const char *lenS1, const char *lenS2, size_t lenN);
char *lenStrcat(char *lenDest, char *lenSrc);
int lenStrlen(char *lenStr);
char *lenMemset(char *lenS, char lenB, unsigned int lenN);
void len_builtin(char **len_tokenize, char **len_env, char **len_buff, int len_status);
char *len_readline(void);
void len_sfree(char *len_str);
void len_nfree(char **len_str);
void lenEnvBuiltin(char **lenEnv);
void lenFree(char **lenTokenize, char *lenBuff);
void lenDoubleFree(char **lenTokenize, char *lenBuff);
int lenExit(int lenStatus);

#endif
