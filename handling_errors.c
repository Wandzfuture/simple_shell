#include "shell.h"

/**
 * handle_error - displays an error message and terminates the program.
 * @msg: error message displayed
 */
void handle_error(const char *msg)
{
        perror(msg);
        exit(EXIT_FAILURE);
}
