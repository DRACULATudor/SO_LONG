/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:19:54 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/24 19:16:02 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	fill(char **tab, t_point size, t_point begin, char to_fill[])
{
	char	c;
	int		i;

	if (begin.y < 0 || begin.y >= size.y || begin.x < 0 || begin.x >= size.x)
		return ;
	c = tab[begin.y][begin.x];
	i = 0;
	while (i < 4)
	{
		if (c == to_fill[i])
		{
			tab[begin.y][begin.x] = 'X';
			if (to_fill[i] == 'E')
				return ;
			fill(tab, size, (t_point){begin.x - 1, begin.y}, to_fill);
			fill(tab, size, (t_point){begin.x + 1, begin.y}, to_fill);
			fill(tab, size, (t_point){begin.x, begin.y - 1}, to_fill);
			fill(tab, size, (t_point){begin.x, begin.y + 1}, to_fill);
			break ;
		}
		i++;
	}
}

int	check_if_c_e_p(char **map2)
{
	int	i;
	int	j;

	i = 0;
	while (map2[i] != NULL)
	{
		j = 0;
		while (map2[i][j] != '\0')
		{
			if (map2[i][j] == 'P' || map2[i][j] == 'C' || map2[i][j] == 'E')
			{
				write(2, "Error\n", 7);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

char	**init_map2_and_fill(char **map, t_point size, t_point begin)
{
	int		i;
	char	**map2;
	char	to_fill[4];

	to_fill[0] = 'P';
	to_fill[1] = '0';
	to_fill[2] = 'C';
	to_fill[3] = 'E';
	map2 = malloc(sizeof(char *) * (size.y + 1));
	if (!map2)
		return (NULL);
	i = -1;
	while (++i < size.y)
	{
		map2[i] = ft_strdup(map[i]);
		if (!map2[i])
		{
			free_arr(map2);
			return (NULL);
		}
	}
	map2[i] = NULL;
	fill(map2, size, begin, to_fill);
	return (map2);
}

int	check_valid(char **map, t_point size, t_point begin)
{
	char	**map2;
	int		valid;

	map2 = init_map2_and_fill(map, size, begin);
	if (!map2)
		return (0);
	valid = check_if_c_e_p(map2);
	free_arr(map2);
	return (valid);
}

int	check_map(char **map)
{
	t_point	size;
	t_point	begin;

	if (map == NULL || map[0] == NULL)
		return (0);
	size.x = 0;
	size.y = 0;
	while (map[0][size.x])
		size.x++;
	while (map[size.y])
		size.y++;
	begin.x = get_p_x(map);
	begin.y = get_p_y(map);
	return (check_valid(map, size, begin));
}
