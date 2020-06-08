/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 08:50:22 by pntsunts          #+#    #+#             */
/*   Updated: 2020/06/08 15:52:00 by pntsunts         ###   ########.fr       */
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
	return (0);
}
void	test(int ac, char **av, P_flags *F_lags, t_files tmp[])
{
	int i;
	i = 1;

	if (!ft_checkf(av[i]) && !ft_isdir(av[i]))
	{
		ft_putstr("no such file or directory!!!!!\n");
		return ;
	}
	while (i < ac && ft_checkf(av[i]))
	{
		ft_confirm(ac, av, F_lags);
		if (F_lags->l_flag == 1)
		{
			if (ac > 2)
			{
				printing(av, tmp);
			}
			else
				see(".", tmp);
		}
   		if (F_lags->Re_flag == 1)
		{
			sion(".");
			recur(".");
		}
		if (F_lags->a_flag == 1)
			ls_a(".", tmp);
		if (F_lags->r_flag == 1)
			printr(".", tmp);
		if (F_lags->t_flag == 1)
			printtime(".", tmp);
		i++;
	}
}

