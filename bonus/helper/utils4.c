/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:10:52 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/19 17:17:51 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	validate_args(int argc, char **argv, t_mlx *win)
{
	int	i;

	if (argc != 2)
		return (1);
	win->exit = false;
	i = ft_strleng(argv[1]);
	if (i < 4 || (argv[1][i - 4] != '.' || argv[1][i - 3] != 'b' || argv[1][i
			- 2] != 'e' || argv[1][i - 1] != 'r'))
		return (1);
	return (0);
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

void	init_bullet(t_bullet *bullet)
{
	bullet->counter = -1;
	bullet->frame = 1;
	bullet->bullet_i = -1;
	bullet->bullet_j = -1;
	bullet->initial_i = -1;
	bullet->initial_j = -1;
}

int	validate_map_size(char **map)
{
	int width = strlen(map[0]);
	int height = 0;
	while (map[height] != NULL)
	{
		height++;
	}
	if (width > MAX_WIDTH || height > MAX_HEIGHT)
	{
		ft_printf("Error: The map is too large.\n");
		return (-1);
	}
	return (0);
}
