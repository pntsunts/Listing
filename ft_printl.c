/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 08:48:26 by pntsunts          #+#    #+#             */
/*   Updated: 2020/06/08 13:32:17 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printing(char **av, t_files tmp[])
{
	int		i;
	int		j;
	char	*s1;
	char	*s2;

	i = 0;
	j = 0;
	while (av[i])
	{
		if (ft_isdir(av[i]) && !ft_checkf(av[i]))
		{
			loopdir(av[i], tmp);
			j = 0;
			while (tmp[j].name != NULL)
			{
				s1 = ft_strjoin(av[i], "/");
				s2 = ft_strjoin(s1, tmp[j].name);
				printl(s2);
				free(s1);
				free(s2);					
				j++;
			}
		}
		else
		{
				printl(av[i]);
		}
		i++;	
	}

}


void	see(char *dir_name, t_files tmp[])
{
	int i;
	char *s1;
	char *s2;
 	loopdir(dir_name, tmp);
	i = ft_structlen(tmp);
	sortls(tmp, i);
	i = 0;
	while (tmp[i].name != NULL)
	{
		s1 = ft_strjoin(dir_name, "/");
		s2 = ft_strjoin(s1, tmp[i].name);
		printl(s2);
		free(s1);
		free(s2);
		i++;
	}

}

void	loopdir(char *av, t_files data[])
{
	DIR		*directory;
	struct dirent *folders;
	int i = 0;

	directory = opendir(av);
	while ((folders = readdir(directory)) != NULL)
	{
		if (folders->d_name[0] != '.')
		{
			data[i].name = ft_strdup(folders->d_name);
			i++;
		}
	}
	closedir(directory);
}

void	printl(char *dir_name)
{
	struct stat filestat;

	stat(dir_name, &filestat);
	permission(dir_name);
	ft_putstr("	 ");
	ft_putnbr(filestat.st_nlink);
	ft_putstr("  ");
	ft_putstr(username(filestat.st_uid));
	ft_putstr("  ");
	ft_putstr(grpname(filestat.st_gid));
	ft_putstr("  ");
	ft_putnbr(filestat.st_size);
	ft_putstr("  ");
	ptime(ctime(&filestat.st_mtime));
	ft_putstr("  ");
	ft_putendl(dir_name);
}

void 	permission(char *dir_name)
{
	struct stat filestat;

	stat(dir_name, &filestat);

	ft_putchar((S_ISDIR(filestat.st_mode)) ? 'd' : '-');
	ft_putchar((filestat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((filestat.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((filestat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((filestat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((filestat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((filestat.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((filestat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((filestat.st_mode & S_IWOTH) ? 'w' : '-');
}

char	*username(uid_t name)
{
	struct	passwd *pass;
	pass = getpwuid(name);
	return (pass->pw_name);
}

char	*grpname(gid_t name)
{
	struct group *grp;
	grp = getgrgid(name);
	return (grp->gr_name);
}

void	ptime(char *str)
{
	size_t	i;

	i = 4;
	while (i < 16)
		ft_putchar(str[i++]);
}
