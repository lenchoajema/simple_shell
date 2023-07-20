#include "shell.h"

/**
 * len_sfree - free if the variable ~NULL.
 * @len_str: string from main function.
 */
void len_sfree(char *len_str)
{
	if (len_str != NULL)
		free(len_str);
}

/**
 * len_nfree - len_sfree free str.
 * @len_str: string pointer from main function.
 */
void len_nfree(char **len_str)
{
	if (len_str)
		free(len_str);
}

/**
 * len_readline - read the buffer input.
 * Return: buffer.
 */
char *len_readline(void)
{
	char *len_buff = NULL;
	ssize_t len_lineptr = 0;
	size_t len_size = 0;

	if (isatty(STDIN_FILENO))
		len_puts("$ ");
	len_lineptr = getline(&len_buff, &len_size, stdin);
	if (len_lineptr == -1)
	{
		free(len_buff);
		if (isatty(0))
			len_puts("\n");
		exit(0);
	}
	if (len_buff[len_lineptr - 1] == '\n')
		len_buff[len_lineptr - 1] = '\0';
	return (len_buff);
}
