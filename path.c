#include "shell.h"

/**
 * len_pathvalue - value of environ.
 * @len_env: an array of string to environ
 * Return: token or NULL.
 */
char *len_pathvalue(char **len_env)
{
	char *len_token, *len_temp;
	int len_i = 0;

	while (len_env[len_i])
	{
		len_temp = len_env[len_i];
		len_token = strtok(len_temp, "=");
		if (lenStrcmp(len_token, "PATH") == 0)
		{
			len_token = strtok(NULL, "=");
			return (len_token);
		}
		len_i++;
	}
	return (NULL);
}

/**
 * len_strstr -  a function that locates a substring.
 * @len_haystack: string character value.
 * @len_needle: substring character value.
 * Return: Returns a pointer to substring.
 */
char *len_strstr(char *len_haystack, char *len_needle)
{
	int len_i, len_j = 0;

	if (len_needle[len_j] == '\0')
		return (len_haystack);
	for (len_i = 0; len_haystack[len_i] != '\0'; len_i++)
	{
		if (len_haystack[len_i] == len_needle[0])
		{
			for (len_j = 0; len_needle[len_j] != '\0' && len_haystack[len_i + len_j]
			&& len_needle[len_j] == len_haystack[len_i + len_j]; len_j++)
				;
			if (len_needle[len_j] == 0)
				return (len_haystack + len_i);
		}
	}
	return (0);
}

/**
 * len_pathch - tokenize path and check if the buffer exists.
 * @len_token: the string tokenizedddd the buffer in startsh file.
 * @len_env: array of string to environ.
 * Return: the buffer.
 */
char *len_pathch(char *len_token, char **len_env)
{
	static char len_buffer[1024] = {0};
	char *len_path, *len_a, *len_b, *len_tok;
	struct stat len_st;

	len_path = len_pathvalue(len_env);
	if (!len_path)
		len_path = "";
	len_a = len_strstr(len_path, "::");
	len_b = len_strstr(len_path, ":/bin");
	if (len_path[0] == ':' || (len_a && (len_a < len_b)))
	{
		if (stat(len_token, &len_st) == 0)
			return (len_token);
	}
	len_tok = strtok(len_path, ":");
	while (len_tok)
	{
		lenStrcat(len_buffer, len_tok);
		lenStrcat(len_buffer, "/");
		lenStrcat(len_buffer, len_token);
		if (stat(len_buffer, &len_st) == 0)
			return (len_buffer);
		len_tok = strtok(NULL, ":");
		lenMemset(len_buffer, 0, 1024);
	}
	return (len_token);
}
