#include "simp_sh.h"

/**
 * exe_P - calls the fnc that calls execve
 * @shCommand: actual shell command itself
 * @vec_arg: arguments to the shell cmd
 * @pathName: the program path
 */
void exe_P(const char *shCommand, char *const vec_arg[], char *pathName)
{
		pid_t pid = fork();

		if (pid == 0)
		{
			execvp(shCommand, vec_arg);
			perror(pathName);
			exit(1);
		}
		else if (pid > 0)
		{
			int status;

			waitpid(pid, &status, 0);
		}
		else
		{
			perror("Fork failed");
		}
}


/**
 * file_Exec - handles execve
 * @shCommand: cmd to be executed
 * @pathName: path to program to be executed
 * @vec_arg: arguments of the command
 */
void file_Exec(const char *shCommand, char *const vec_arg[], char *pathName)
{
	if (access(shCommand, X_OK) == 0)
	{
		pid_t pid = fork();

		if (pid == 0)
		{
			execve(shCommand, vec_arg, NULL);
			perror(pathName);
			exit(1);
		}
		else if (pid > 0)
		{
			int status;

			waitpid(pid, &status, 0);
		}
		else
		{
			perror("Fork failed");
		}
	}
	else
	{
		exe_P(shCommand, vec_arg, pathName);
	}
}
