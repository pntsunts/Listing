/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:09:56 by pntsunts          #+#    #+#             */
/*   Updated: 2019/07/01 16:46:58 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*y;

	i = 0;
	y = (char *)malloc((ft_strlen(s1) + 1) * sizeof(*y));
	if (y == NULL)
		return (NULL);
	while (s1[i])
	{
		y[i] = s1[i];
		i++;
	}
	y[i] = '\0';
	return (y);
}
