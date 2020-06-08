/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 08:49:11 by pntsunts          #+#    #+#             */
/*   Updated: 2020/06/08 08:49:32 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_time(const char *dir_name, t_files data[])
{
	DIR				*directory;
	struct dirent 	*folders;
	struct stat   t_f;
	int i = 0;

	directory = opendir(dir_name);
	while ((folders = readdir(directory)) != NULL)
	{
		if (folders->d_name[i] != '.')
		{
			data[i].name = ft_strdup(folders->d_name);
			if (lstat(data[i].name, &t_f) < 0)
			{
				printf("ERROR");
				return ;
			}
			data[i].mtime = t_f.st_mtime;
			i++;
		}
	}
	closedir(directory);
}

void printtime(const char *dir_name, t_files data[])
{
	ft_time(dir_name, data);
	ft_displaytime(data, ft_structlen(data));
}

int		ft_structlen(t_files length[])
{
	int	i;

	i = 0;
	while (length[i].name != NULL)
		i++;
	return (i);
}

void	ft_displaytime(t_files test[], int n)
{
	n--;
	sortls(test, n);
	sorting(test, n);
	while (n >= 0)
	{
		if (*test[n].name != '.')
		{
			ft_putendl(test[n].name);
			ft_strdel(&test[n].name);
		}
		n--;
	}
}

void	sorting(t_files data[], int n)
{
	int		i;
	int		j;
	t_files	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (data[j].mtime > data[j + 1].mtime)
			{
				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
