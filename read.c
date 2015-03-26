/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <nchampot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 14:47:31 by nchampot          #+#    #+#             */
/*   Updated: 2015/03/26 15:09:49 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**read_cmd(void)
{
	char	*buf;
	char	**tab;

	get_next_line(0, &buf);
	tab = ft_strsplit(buf, ' ');
	return (tab);
}
