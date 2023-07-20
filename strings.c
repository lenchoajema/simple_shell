#include "shell.h"

/**
 * lenStrcat - concatenates two strings.
 *@lenDest: destination string.
 *@lenSrc: source string.
 * Return: lenDest value.
 */
char *lenStrcat(char *lenDest, char *lenSrc)
{
	int lenA, lenB;

	for (lenA = 0; lenDest[lenA] != '\0'; lenA++)
		;
	lenB = 0;
	while (lenSrc[lenB] != '\0')
	{
		lenDest[lenA] = lenSrc[lenB];
		lenB++;
		lenA++;
	}
	lenDest[lenA] = '\0';
	return (lenDest);
}

/**
 * lenStrcmp - function that compares strings.
 * @lenS1: first string.
 * @lenS2: second string.
 * Return: 0 if the strings are equal, otherwise the difference.
 */
int lenStrcmp(char *lenS1, char *lenS2)
{
	int lenI = 0, lenJ = 0, lenK = 0;

	while (lenS1[lenI] != '\0' || lenS2[lenJ] != '\0')
	{
		if (lenS1[lenI] == lenS2[lenJ])
		{
			lenI++;
			lenJ++;
		}
		else if (lenS1[lenI] != lenS2[lenJ])
		{
			lenK = lenS1[lenI] - lenS2[lenJ];
			break;
		}
	}
	return (lenK);
}

/**
 * lenStrlen - returns the length of a string.
 * @lenStr: character value.
 * Return: lenI
 */
int lenStrlen(char *lenStr)
{
	int lenI = 0;

	while (lenStr[lenI])
		lenI++;
	return (lenI);
}

/**
 * lenMemset - fills memory with a constant n.
 * @lenS: string value.
 * @lenB: character value.
 * @lenN: integer value.
 * Return: string value.
 */
char *lenMemset(char *lenS, char lenB, unsigned int lenN)
{
	unsigned int lenI;

	for (lenI = 0; lenI < lenN; lenI++)
		lenS[lenI] = lenB;
	return (lenS);
}

/**
 * lenStrncmp - compares up to n characters between two strings.
 * @lenS1: first string.
 * @lenS2: second string.
 * @lenN: characters to compare.
 * Return: the result.
 */
int lenStrncmp(const char *lenS1, const char *lenS2, size_t lenN)
{
	int lenI = 0, lenK = 0, lenJ = 0;

	while ((lenS1[lenI] || lenS2[lenJ]) && lenN--)
	{
		if (lenS1[lenI] == lenS2[lenJ])
		{
			lenI++;
			lenJ++;
		}
		else if (lenS1[lenI] != lenS2[lenJ])
		{
			lenK = lenS1[lenI] - lenS2[lenJ];
			break;
		}
	}
	return (lenK);
}
