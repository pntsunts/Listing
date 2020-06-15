/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 14:29:58 by pntsunts          #+#    #+#             */
/*   Updated: 2020/06/15 15:11:30 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	permerror(char *path)
{
	ft_putstr(path);
	ft_putstr("Permission denied");
}

int printerror(char *path)
{ 
	if (errno == 13)
	{
		permerror(path);
		return (1);
	}
	return (0);
}
