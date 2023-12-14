#ifndef SIMP_SH_H
#define SIMP_SH_H

/* Standard lib. fnc. here */
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>

/* user def. fnc. */
void token_shCommand(const char *userInput, char *pathName);
int exe_Disp(char *console_stdout);
void console_Print(const char *stdoutText);
void file_Exec(const char *shCommand, char *const vec_arg[], char *pathName);
void exe_P(const char *shCommand, char *const vec_arg[], char *pathName);
int _str_cmp(const char *str_A, const char *str_B);
char *dup_str(const char *originalStr);
void handle_env(char *const environVar[]);
char *custom_Strtok(char *originalStr, const char *delimit);

/*additionally*/
char *exec_getline(char *input_buff, size_t *n);
void spec_str(char *buffer, char *checker, char *v_argv[]);
char *exec_getline(char *input_buff, size_t *n);
size_t sh_strspn(const char *source_str, const char *comp_str);
char *sh_strchr(const char *source_str, int ch);
size_t sh_strcspn(const char *source_str, const char *forbidden_chars);

#endif
