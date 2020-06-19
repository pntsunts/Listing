/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_confirm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 08:37:32 by pntsunts          #+#    #+#             */
/*   Updated: 2020/06/19 08:54:08 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int		ft_isoption(char c)
{
	if (c == 'l')
		return (1);
	if (c == 'a')
		return (1);
	if (c == 'r')
		return (1);
	if (c == 't')
		return (1);
	if (c == 'R')
		return (1);
	return (0);
}

void	ft_confirm(int ac, char **av, P_flags *F_lags)
{
	int i;
	int j;

	F_lags->l_flag = 0;
	F_lags->a_flag = 0;
	F_lags->r_flag = 0;
	F_lags->t_flag = 0;
	F_lags->Re_flag = 0;

	i = 1;

	while (i < ac)
	{
		if (ft_checkf(av[i]))
		{
			j = 1;
			while (av[i][j] != '\0')
			{
				if (!ft_isoption(av[i][j]))
				{
					ft_putstr("illegal option ----\n");
					break;
				}
				if (av[i][j] == 'l')
					F_lags->l_flag = 1;
				else if (av[i][j] == 'a')
					F_lags->a_flag = 1;
				else if (av[i][j] == 'r')
					F_lags->r_flag = 1;
				else if (av[i][j] == 't')
					F_lags->t_flag = 1;
				else if (av[i][j] == 'R')
					F_lags->Re_flag = 1;
				j++;
			}
		}
		i++;
	}
}
