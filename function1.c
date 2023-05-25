#include "main.h"

/**
 * _strlen - returns the length of a string
 * @str: string to be measured
 * Return: length of string
 */

int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * _strncmp - compares two strings
 * @str1: first string
 * @str2: second string
 * @n: number of bytes to compare
 * Return: 0 if strings are equal, -1 if not
 */

int _strncmp(char *str1, char *str2, int n)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0' && i < n)
	{
		if (str1[i] != str2[i])
			return (-1);
		i++;
	}
	if (i == n)
		return (0);
	return (-1);
}

/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 * Return: pointer to the duplicated string
 */

char *_strdup(char *str)
{
	int i = 0;
	char *duplicated_str = NULL;

	if (str == NULL)
		return (NULL);
	duplicated_str = malloc(sizeof(char) * (_strlen(str) + 1));
	if (duplicated_str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		duplicated_str[i] = str[i];
		i++;
	}
	duplicated_str[i] = '\0';
	return (duplicated_str);
}

/**
 * sigintHandler - handles the SIGINT signal
 * @sig_num: signal number
 * Return: void
 */

void sigintHandler(int sig_num)
{
	(void)sig_num;
	signal(SIGINT, sigintHandler);
	fflush(stdout);
}
