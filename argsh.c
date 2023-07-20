#include "shell.h"

/**
 * len_strdup - create an array with special character.
 * @len_str: character value.
 * Return: duplicated string.
 */
char *len_strdup(char *len_str)
{
	unsigned int len_i;
	char *len_s;

	if (len_str == NULL)
		return (NULL);

	for (len_i = 0; len_str[len_i] != '\0'; len_i++)
		;

	len_i = len_i + 1;
	len_s = malloc(sizeof(char) * len_i);

	if (len_s == NULL)
		return (NULL);

	if (len_s != NULL)
	{
		for (len_i = 0; len_str[len_i] != '\0'; len_i++)
			len_s[len_i] = len_str[len_i];
	}

	len_s[len_i] = '\0';
	return (len_s);
}

/**
 * len_handletok - takes buffer input and tokenizes it
 * @len_buffer: buffer input from main function.
 * Return: array of string after tokenization.
 */
char **len_handletok(char *len_buffer)
{
	char *len_token, **len_arr;
	int len_i, len_word = 1, len_flag = 0, len_j = 0;

	for (len_i = 0; len_buffer[len_i] && len_buffer[len_i + 1]; len_i++)
	{
		if (len_buffer[len_i] != ' ')
			len_flag = 1;
		if (len_buffer[len_i] == ' ')
			len_flag = 0;
		if (len_flag == 0 && len_buffer[len_i] == ' ' && len_buffer
				[len_i + 1] != ' ')
			len_word++;
	}

	len_arr = malloc(sizeof(char *) * (len_word + 1));

	if (!len_arr)
		return (NULL);

	len_token = strtok(len_buffer, " \t\n");

	if (!len_token)
	{
		free(len_arr);
		return (NULL);
	}

	while (len_token)
	{
		len_arr[len_j] = len_strdup(len_token);
		len_token = strtok(NULL, " \t\n");
		len_j++;
	}

	len_arr[len_j] = NULL;
	return (len_arr);
}
