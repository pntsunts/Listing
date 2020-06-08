/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 08:45:53 by pntsunts          #+#    #+#             */
/*   Updated: 2020/06/08 09:12:54 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

#include "libft/libft.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

typedef struct flags
{
	int	l_flag;
	int a_flag;
	int r_flag;
	int Re_flag;
	int t_flag;
}		P_flags;

typedef struct		s_files
{
	char			*name;
	struct stat		filestat;
	time_t			mtime;
}				t_files;

void ls_a(const char *dir_name, t_files store[]);
void ls(const char *dir_name, t_files store[]);
void sortls(t_files *data, int n);
void see(char *dir_name, t_files tmp[]);
int ft_structlen(t_files length[]);
void ft_displaytime(t_files test[], int n);
void sorting(t_files data[], int n);
void	printtime(const char *dir_name, t_files data[]);
void revsort(t_files data[]);
void ft_time(const char *dir_name, t_files data[]);
void printr(const char *dir_name, t_files store[]);
void sion(const char *dir_name);
void recur(const char *dir_name);
void ft_ls(const char *dir_name, t_files data[]);
void ft_ls_a(const char *dir_name, t_files data[]);
void printrev(const char *dir_name, t_files data[]);
void ft_perm(const char *dir_name);
int	ft_checkf(char *av);
void ft_confirm(int ac, char **av, P_flags *F_lags);
void test(int ac, char **av, P_flags *F_lags, t_files tmp[]);
void permission(char *dir_name);
void printl(char *dir_name);
char *username(uid_t name);
char *grpname(gid_t name);
void ptime(char *str);
void printing(char **av, t_files data[]);
int ft_isdir(const char *dir_name);
void loopdir(char *av, t_files data[]);

#endif
