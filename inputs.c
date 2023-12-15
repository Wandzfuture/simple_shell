#include "shell.h"

/**
 * read_cmd - Read a line of input from the standard input (stdin).
 *
 * Description: This function reads a line of input from the standard input
 * and dynamically allocates memory to store the input line.
 *
 * Return: A dynamically allocated string,
 * containing the input line from stdin.
 */
char *read_cmd()
{
	char *line = NULL;
	size_t buffsize = 0;

	ssize_t n = getline(&line, &buffsize, stdin);
	if (n == -1)
	{
		if (feof(stdin))    /*Input stream has reached the end */
		{
			return (NULL);
		}
		else    /*An error has occurred while reading from stdin */
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}

	if (n == 0)
	{
		return (calloc(1, sizeof(char)));
	}
	/*We remove the newline character from the input line */
	line[n - 1] = '\0';

	return (line);
}
