#include "../so_long.h"

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
				free_arr(map2);
				return(error_fct(1));
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_valid(char **map, int x, int y, int map_width, int map_height)
{
	t_point	size;
	int		i;
	int		valid;
	t_point	begin;
	char	to_fill[6];
	char	**map2;

	to_fill[0] = 'P';
	to_fill[1] = '0';
	to_fill[2] = 'C';
	to_fill[3] = 'E';
	size.x = map_width;
	size.y = map_height;
	i = -1;
	begin.x = 0;
	begin.y = 0;
	begin.x = x;
	begin.y = y;
	map2 = malloc(sizeof(char *) * (map_height + 1));
	while (++i < map_height)
		map2[i] = ft_strcpy(map2[i], map[i]);
	map2[i] = NULL;
	fill(map2, size, begin, to_fill);
	i = 0;
	valid = check_if_c_e_p(map2);
	free_all(map2);
	return (valid);
}

int	check_map(char **map)
{
	int	x;
	int	y;
	int	valid;
	int	p_x;
	int	p_y;

	x = 0;
	y = 0;
	p_x = 0;
	p_y = 0;
	while (map[0][x])
		x++;
	while (map[y])
		y++;
	p_x = get_p_x(map);
	p_y = get_p_y(map);
	valid = check_valid(map, p_x, p_y, x, y);
	return (valid);
}
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
