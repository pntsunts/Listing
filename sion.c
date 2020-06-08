/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sion.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 08:52:50 by pntsunts          #+#    #+#             */
/*   Updated: 2020/06/08 13:54:20 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sion(const char *dir_name)
{
	DIR				*directory;
	char			*data;
	struct dirent	*folder;

	directory = opendir(dir_name);
	data = (char *)malloc(sizeof(char) * 4080);
	if (!directory)
	{
		ft_putstr("Can't open the directory");
		return ;
	}
//	ft_putchar('\n');
	while ((folder = readdir(directory)) != NULL)
	{
		if (folder->d_name[0] != '.' && folder->d_type == DT_DIR)
		{
			ft_strcpy(data, dir_name);
			ft_strcat(data, "/");
			ft_strcat(data, folder->d_name);
			recur(data);
		}
	}
	closedir(directory);
	free(data);
}
