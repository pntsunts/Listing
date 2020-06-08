/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 08:46:37 by pntsunts          #+#    #+#             */
/*   Updated: 2020/06/08 09:06:35 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_a(const char *dir_name, t_files data[])
{
	DIR				*directory;
	struct dirent	*folders;
	int i = 0;

	directory = opendir(dir_name);
	while ((folders = readdir(directory)) != NULL)
	{
		if (folders->d_name[0] != '\0')
		{
			data[i].name = ft_strdup(folders->d_name);
			i++;
		}
	}
	closedir(directory);
}

void	ls_a(const char *dir_name, t_files store[])
{
	int i ;

	ft_ls_a(dir_name, store);
	i = ft_structlen(store);
	sortls(store, i);
	i = 0;
	while (store[i].name != NULL)
		ft_putendl(store[i++].name);
	return ;

}
