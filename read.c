/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <nchampot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 14:47:31 by nchampot          #+#    #+#             */
/*   Updated: 2015/04/02 16:10:08 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**read_cmd(void)
{
	char	*buf;
	char	**tab;

    ft_putstr(ft_getenv("PWD"));
    ft_putstr(" 3===D ");
	if (get_next_line(0, &buf) == 0)
        return (NULL);
	tab = ft_strsplit(buf, ' ');
	return (tab);
}
