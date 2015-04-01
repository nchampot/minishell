//
//  minishell.h
//  minishell
//
//  Created by gwendal lasson on 3/25/15.
//  Copyright (c) 2015 gwendal lasson. All rights reserved.
//

#ifndef __minishell__minishell__
#define __minishell__minishell__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/inc/libft.h"
#include <sys/wait.h>

typedef int (*fptr)(const char **str);

typedef struct  s_bcmd
{
    fptr          func;
    const char    *name;
}               t_bcmd;

char	**read_cmd(void);
int		    fork_exec(const char **cmd);
char        *ft_getenv(const char *var);
int     b_unsetenv(const char **cmd);
int     b_env(const char **cmd);
int     b_setenv(const char **cmd);
int     b_cd(const char **cmd);

#endif /* defined(__minishell__minishell__) */
