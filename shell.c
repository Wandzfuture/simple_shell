#include "shell.h"

/**
 * main - Entry point of the program.
 *
 * Return: (0) on Success
 */
int main(void)
{
        char *line;
        char **command;
	char err_msg[100];

        while (1)
        {
                printf("$ "); /*prompt to be displayed: $ */
                fflush(stdout);

                line = my_getline(stdin);
                if (feof(stdin))
                {
                        printf("\n");
                        free(line);
                        break;
                }

                command = parse_cmd(line, err_msg);
                if (strcmp(command[0], "fetch_env") == 0)
                {
                        if (command[1] != NULL)
                        {
                                fetch_env(command[1]);
                        }
                        else
                        {
                                printf("Usage: fetch_env <environment_variable>\n");
                        }
                }
                else
                {
                        execute_cmd(command);
                }

                free(line);
                free(command);
        }

        return (0);
}
