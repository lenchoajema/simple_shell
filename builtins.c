#include "shell.h"
/**
 * len_builtin - built-in command for shell.
 * @len_tokenize: value tokenized the buffer in startsh file.
 * @len_env: array of string to environ values.
 * @len_buff: buffer input from main.
 * @len_status: value of the exit.
 */
void len_builtin(char **len_tokenize, char **len_env, char **len_buff,
int len_status)
{
	int len_i;
	(void)len_buff;

	if (lenStrcmp(len_tokenize[0], "exit") == 0)
	{
		for (len_i = 0; len_tokenize[len_i]; len_i++)
			free(len_tokenize[len_i]);

		free(*len_buff);
		free(len_tokenize);
		exit(len_status);
	}

	if (lenStrcmp(len_tokenize[0], "env") == 0)
	{
		if (!len_tokenize[1])
			lenEnvBuiltin(len_env);
	}
}
