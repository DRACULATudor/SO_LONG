/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:59:42 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/25 15:05:55 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strleng(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return(i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*sour;
	char	*dest;
	size_t	i;

	sour = (char *)src;
	dest = (char *)dst;
	if (sour > dest)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = sour[i];
			i++;
		}
	}
	else if (sour < dest)
	{
		i = len;
		while (i > 0)
		{
			dest[i - 1] = sour[i - 1];
			i--;
		}
	}
	return (dst);
}

void   *ft_memcpy(void *dst, const void *src, size_t len)
{
    return(ft_memmove(dst, src, len));
}