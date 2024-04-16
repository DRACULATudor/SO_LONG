/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:59:42 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/16 16:28:56 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strleng(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

int	ft_count_num(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count++;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*s;
	size_t	i;

	s = (char *)b;
	i = 0;
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	return (b);
}
void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;

	i = count * size;
	ptr = malloc(i);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_memset(ptr, 0, i);
	return (ptr);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long long	temp;

	temp = n;
	str = (char *)ft_calloc((ft_count_num(n) + 1) * sizeof(char), 1);
	if (str == NULL)
		return (0);
	if (temp == 0)
		str[0] = '0';
	if (temp < 0)
	{
		str[0] = '-';
		temp = temp * -1;
	}
	i = ft_count_num(n);
	while (temp != 0)
	{
		str[i - 1] = (temp % 10) + '0';
		temp = temp / 10;
		i--;
	}
	return (str);
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

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	return (ft_memmove(dst, src, len));
}
