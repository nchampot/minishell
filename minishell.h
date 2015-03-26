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

char	**read_cmd(void);
int		exec_cmd(char **cmd, char **env);

#endif /* defined(__minishell__minishell__) */
