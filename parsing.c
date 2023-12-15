#include "shell.h"

/**
 *tokenize_cmd - Tokenizes the input string into individual words.
 *@line: Input string to be tokenized.
 *@tokens: Pointer to the array of tokenized strings.
 *@tokens_capacity: Number of elements in the tokens array.
 *
 *Description: Iterates through the input string, treating sequences of
 *characters separated by space &newline delimiters as individual tokens.
 *
 *Return: The number of tokens found in the input string.
 */
size_t tokenize_cmd(char *line, char **tokens, size_t tokens_capacity)
{
	size_t num_tokens = 0;
	size_t i = 0;

	while (line[i] != '\0')
	{
		while (line[i] != '\0' && strchr(" \t\n", line[i]) != NULL)
		{
			i++;
		}

		if (line[i] == '\0')
		{
			break;
		}

		if (num_tokens < tokens_capacity)
		{
			tokens[num_tokens++] = &line[i];
		}

		while (line[i] != '\0' && strchr(" \t\n", line[i]) == NULL)
		{
			i++;
		}
	}

	return num_tokens;
}

/**
 *parse_cmd - Parses the input string into tokens.
 *@line: Input string to be parsed into tokens.
 *
 *Description: Calls the tokenize_cmd function to break the input string
 *into individual tokens. It then adds a NULL terminator to the tokens
 *array and returns it.
 *
 *Return: An array of strings (tokens) created from the input string.
 *The last element in the array is (NULL).
 */
char **parse_cmd(char *line, char *err_msg)
{
	char **tokens = NULL;
	size_t num_tokens = 0;
	size_t tokens_capacity = 10;

	tokens = malloc(tokens_capacity * sizeof(char *));
	if (tokens == NULL)
	{
		strcpy(err_msg, "Memory allocation failed.");
		return (NULL);
	}

	num_tokens = tokenize_cmd(line, tokens, tokens_capacity);

	tokens = realloc(tokens, sizeof(char *) * (num_tokens + 1));
	if (tokens == NULL)
	{
		strcpy(err_msg, "Memory reallocation failed.");
		return (NULL);
	}

	tokens[num_tokens] = NULL;

	return (tokens);
}
