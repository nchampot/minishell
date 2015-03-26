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

int		exec_cmd(char **cmd, char **env)
{
	char	buf[256];
	char	**tab_p;
	char	*path;

	path = getenv("PATH");
	tab_p = ft_strsplit(path, ':');
	while (*tab_p)
	{
		*buf = 0;
		ft_strcpy(buf, *tab_p);
		ft_strcat(buf, "/");
		ft_strcat(buf, *cmd);
		execve(buf, cmd, NULL);
		*tab_p++;
	}
	return (0);
}
