/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printrev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 09:07:45 by pntsunts          #+#    #+#             */
/*   Updated: 2020/06/08 12:04:58 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printrev(const char *dir_name, t_files data[])
{
	DIR			*directory;
	struct dirent *folders;
	int i = 0;

	directory = opendir(dir_name);
	while ((folders = readdir(directory)) != NULL)
	{
		if (folders->d_name[i] != '.')
		{
			data[i].name = ft_strdup(folders->d_name);
			i++;
		}
	}
	closedir(directory);
}

