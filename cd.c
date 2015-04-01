#include "minishell.h"

int     b_cd(const char **cmd)
{
    ft_putstr("cd\n");
}

int     b_env(const char **cmd)
{
    ft_putstr("env\n");
}
int     b_setenv(const char **cmd)
{
    ft_putstr("setenv\n");
}
int     b_unsetenv(const char **cmd)
{
    ft_putstr("unsetenv\n");
}
