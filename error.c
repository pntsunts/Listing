/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 14:29:58 by pntsunts          #+#    #+#             */
/*   Updated: 2020/06/16 11:56:25 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(t_files **data, char *Path)
{
	data = NULL;

	if (errno == 13)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(Path);
		ft_putstr(" : Permission Denied");
		exit(0);
	}
	if (errno == 2)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(Path);
		ft_putstr(" : No such file or Diretory");
		exit (0);
	}
}
