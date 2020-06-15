/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 14:29:58 by pntsunts          #+#    #+#             */
/*   Updated: 2020/06/15 16:50:52 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	permerror(char *path)
{
	//ft_putstr(path);
	//ft_putstr("Permission denied");
	if (path[ft_strlen(path) - 1] != '/')
		ft_putstr(path);
	ft_putstr(":permission denied");
}

int printerror(char *path,int ierrno)
{ 
	if (ierrno == 13)
	{
		permerror(path);
		return (1);
	}
	return (0);
}
