#include "shell.h"

/*
 * my_getline - Reads a line from the specified stream & dynamically,
 * allocates memory to store the characters of the line.
 * @stream: A pointer to the FILE stream which is read.
 *
 * Returns: A pointer to the dynamically allocated buffer
 */
char *my_getline(FILE *stream)
{
        size_t size = INIT_SIZE;
        char *buffsize = malloc(size * sizeof(char));
        char *cursor = buffsize, *temp = NULL;
        size_t length = 0;

        if (buffsize == NULL)
        {
                return (NULL);
        }

        while (1)
        {
                char c = fgetc(stream);

                if (c == EOF || c == '\n')
                {
                        break;
                }

                *cursor++ = c;
                length++;

                if (length == size - 1)
                {
                        size *= EXP_FACTOR;
                        temp = realloc(buffsize, size * sizeof(char));
                        if (temp == NULL)
                        {
                                free(buffsize);
                                return (NULL);
                        }

                        buffsize = temp;
                        cursor = buffsize + length;
                }
        }

        *cursor = '\0';
        return (buffsize);
}
