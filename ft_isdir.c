/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 08:38:13 by pntsunts          #+#    #+#             */
/*   Updated: 2020/06/08 08:38:40 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_isdir(const char *dir_name)
{
	struct stat filestat;

	stat(dir_name, &filestat);
	if (S_ISDIR(filestat.st_mode))
		return (1);
	return (0);
}
