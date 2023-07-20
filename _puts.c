#include "shell.h"
#include <unistd.h>

/**
 * len_putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int len_putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * len_puts - puts function strings
 * @str: character value.
 */
void len_puts(char *str)
{
int i;

for (i = 0; str[i] != '\0'; i++)
len_putchar(str[i]);
}
