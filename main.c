/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 08:50:22 by pntsunts          #+#    #+#             */
/*   Updated: 2020/06/17 10:22:34 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	P_flags *F_lags = (P_flags*)malloc(sizeof(P_flags));
	t_files tmp[1024];
	int i = 0;

	if (ac < 2)
	{
		if (av[i][0] != '-')
		{
			ls(".", tmp);
		} 
	}
	else
	{
		test(ac, av, F_lags, tmp);
	}
//	sleep(10);
	return (0);
}
void	test(int ac, char **av, P_flags *F_lags, t_files tmp[])
{
	int i;
	i = 1;

	while (i < ac && ft_checkf(av[i]))
	{
		ft_confirm(ac, av, F_lags);
		if (F_lags->l_flag && F_lags->t_flag)
		{
		//	see(".", tmp);
			multiple(".", tmp);
			exit(1);
		}
		else
		{
			if (F_lags->l_flag == 1)
			{
				if (ac > 2)
				{
					printing(av, tmp);
				}
				else
					see(".", tmp);
			return;
			}
   			if (F_lags->Re_flag == 1)
			{
				sion(".");
				recur(".");
				return ;
			}
			if (F_lags->a_flag == 1)
			{
				ls_a(".", tmp);
				return ;
			}
			if (F_lags->r_flag == 1)
			{
				if (ac > 2)
				{
					several(av, i, tmp);
				}
				else
				{
					printr(".", tmp);
				}
				return ;
			}
			if (F_lags->t_flag == 1)
			{
				if (ac > 2)
				{
					moretime(av, i, tmp);
				}
				else
				{
					printtime(".", tmp);
				}
				return ;
			}
		//	i++;
		}
		i++;
	}
	while (av[i] != NULL)
	{
		if (!(opendir(av[i])))
		{
			ft_error(&tmp, av[i]);
			return ;
		}
	}
}
