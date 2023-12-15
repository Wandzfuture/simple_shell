#include "shell.h"

/**
 * fetch_env - handles the PATH in the shell
 * @env_name: the name of the environment to fetch.
 */
void fetch_env(char *env_name)
{
        if (env_name == NULL)
        {
                char **env_var = NULL;

                for (env_var = environ; *env_var != NULL; env_var++)
                {
                        write(1, *env_var, strlen(*env_var));
                        write(1, "\n", 1);
                }
        }
        else
        {
                char *env_val = getenv(env_name);

                if (env_val != NULL)
                {
                        write(1, env_val, strlen(env_val));
                        write(1, "\n", 1);
                }
                else
                {
                        char *msg = "No such environment variable: ";

                        write(1, msg, strlen(msg));
                        write(1, env_name, strlen(env_name));
                        write(1, "\n", 1);
                }
        }
}
