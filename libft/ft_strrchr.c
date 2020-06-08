/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:49:08 by pntsunts          #+#    #+#             */
/*   Updated: 2019/07/01 15:30:50 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *s, int c)
{
	int		x;

	x = ft_strlen(s);
	if (c == 0)
		return ((char *)s + x);
	while (x >= 0)
	{
		if (s[x] == c)
			return ((char *)s + x);
		x--;
	}
	return (NULL);
}
