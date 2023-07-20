#include "shell.h"

/**
 * lenEnvBuiltin - environment built-in.
 * @lenEnv: the array of string of environment values.
 */
void lenEnvBuiltin(char **lenEnv)
{
	int lenI;

	if (lenEnv)
	{
		for (lenI = 0; lenEnv[lenI]; lenI++)
		{
			len_puts(lenEnv[lenI]);
			len_putchar('\n');
		}
	}
}

/**
 * main - run simple shell finally.
 * @lenAc: argument count.
 * @lenAv: argument var.
 * @lenEnv: array of string.
 * Return: Always 0.
 */
int main(int lenAc, __attribute__((unused)) char **lenAv, char **lenEnv)
{
	char *lenBuff = NULL, *lenPath, **lenTokenize;
	int lenStatus = 0, lenNumber = 0;
	pid_t lenPid;
	(void)lenAc;

	while (1)
	{
		lenBuff = len_readline();
		lenTokenize = NULL;
		lenTokenize = len_handletok(lenBuff);
		if (!lenTokenize)
			continue;
		len_builtin(lenTokenize, lenEnv, &lenBuff, lenNumber);
		lenPid = fork();
		if (lenPid == -1)
		{
			perror("Error:");
			lenDoubleFree(lenTokenize, lenBuff);
			return (1);
		}
		if (lenPid == 0)
		{
			lenPath = len_pathch(lenTokenize[0], lenEnv);
			if (execve(lenPath, lenTokenize, NULL) == -1)
			{
				perror(lenTokenize[0]);
				lenFree(lenTokenize, lenBuff);
				exit(0);
			}
		}
		else
		{
			lenFree(lenTokenize, lenBuff);
			wait(&lenStatus);
			lenNumber = lenExit(lenStatus);
		}
	}
	lenDoubleFree(lenTokenize, lenBuff);
	return (0);
}

/**
 *lenFree - free variable for main.
 * @lenTokenize: the array of strings from main.
 * @lenBuff: buffer input from main function.
 */
void lenFree(char **lenTokenize, char *lenBuff)
{
	int lenI;

	for (lenI = 0; lenTokenize[lenI]; lenI++)
		free(lenTokenize[lenI]);
	len_nfree(lenTokenize);
	len_sfree(lenBuff);
}

/**
 * lenDoubleFree - free variable for main.
 * @lenTokenize: the array of strings from main.
 * @lenBuff: buffer input from main function.
 */
void lenDoubleFree(char **lenTokenize, char *lenBuff)
{
	len_nfree(lenTokenize);
	len_sfree(lenBuff);
}

/**
 * lenExit - return exit from child process
 * @lenStatus: exit value.
 * Return: exit value.
 */
int lenExit(int lenStatus)
{
	int lenNumber;

	if (WIFEXITED(lenStatus))
		lenNumber = WEXITSTATUS(lenStatus);
	return (lenNumber);
}
