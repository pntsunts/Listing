/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 14:21:21 by pntsunts          #+#    #+#             */
/*   Updated: 2020/06/12 14:33:47 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void multiple(char *dir_name, t_files tmp[])
{
	int i;
	char *s1;
	char *s2;
	loopdir(dir_name, tmp);
	i = ft_structlen(tmp);
//	sortls(tmp, i);
//	sorting(tmp, i);
	i = 0;
	while (tmp[i].name != NULL)
	{
		s1 = ft_strjoin(dir_name, "/");
		s2 = ft_strjoin(s1, tmp[i].name);
		printl(s2);
		free(s1);
		free(s2);
		i++;
	}
}
