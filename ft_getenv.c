#include "minishell.h"


char *ft_getenv(const char *var)
{
    extern char **environ;
    char        *val;
    int         i;
    int         len;

    len = ft_strlen(var);
    i = 0;
    while (environ[i])
    {
        if (ft_strnequ(var, environ[i], len))
            return (environ[i] + len + 2);
        i++;
    }
    return (NULL);
}
