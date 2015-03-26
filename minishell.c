//
//  minishell.c
//  minishell
//
//  Created by gwfatheral lasson on 3/25/15.
//  Copyright (c) 2015 gwfatheral lasson. All rights reserved.
//

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	pid_t	father;
	char	**tab;

	(void)ac;
	tab = read_cmd();
	exec_cmd(tab, env);
	return (0);
}
