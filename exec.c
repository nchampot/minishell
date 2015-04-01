/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <nchampot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 15:16:35 by nchampot          #+#    #+#             */
/*   Updated: 2015/03/26 15:50:54 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static const t_bcmd   g_builtin[] ={
    {b_cd,"cd"},
    {b_env, "env"},
    {b_setenv, "setenv"},
    {b_unsetenv, "unsetenv"},
    {NULL, NULL}};

static int      exec_builtin(const char **cmd)
{
    int i;

    i = 0;
    while (g_builtin[i].name)
    {
        if (ft_strequ(g_builtin[i].name, cmd[0]))
        {
            g_builtin[i].func(cmd + 1);
            return (0);
        }
        i++;
    }
    return (1);
}

static int		exec_cmd(const char **cmd, char **env)
{
    char	buf[256];
    char	**tab_p;
    char	*path;

    path = ft_getenv("PATH");
    tab_p = ft_strsplit(path, ':');
    while (*tab_p)
    {
        *buf = 0;
        ft_strcpy(buf, *tab_p);
        ft_strcat(buf, "/");
        ft_strcat(buf, *cmd);
        execve(buf, (char *const*)cmd, NULL);
        *tab_p++;
    }
    return (1);
}

int		    fork_exec(const char **cmd)
{
    pid_t   pid;
    int     status;
    extern char **environ;

    if ((pid = fork()) < 0)
    {
        ft_putstr_fd("Fork failed\n", 2);
        return (1);
    }
    if (pid == 0)
    {
        if (exec_builtin(cmd) == 1)
        {
            exec_cmd(cmd, environ);
            ft_putstr_fd("ftsh1: command not found: ", 2);
            ft_putendl_fd(cmd[0], 2);
        }
        return (1);
    }
    else
    {
        if (wait(&status) < 0)
        {
            ft_putstr_fd("ftsh1: ", 2);
            ft_putstr_fd(cmd[0], 2);
            ft_putendl_fd(" : error occured", 2);
            return (1);
        }
        return (0);
    }
}
