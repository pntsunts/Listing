/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:28:31 by pntsunts          #+#    #+#             */
/*   Updated: 2019/07/01 16:39:17 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *str, const char *to_f, size_t len)
{
	const char	*x;
	const char	*y;
	size_t		i;

	if (*to_f == '\0')
		return ((char*)str);
	while (*str != '\0' && len > 0)
	{
		x = str;
		y = to_f;
		i = len;
		while (*y != '\0' && *x == *y && i--)
		{
			x++;
			y++;
		}
		if (*y == '\0')
			return ((char*)str);
		str++;
		--len;
	}
	return (NULL);
}
