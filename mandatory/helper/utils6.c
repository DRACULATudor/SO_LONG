/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:59:12 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/24 16:01:40 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	error_fct(int num)
{
	num = 1;
	write(2, "Error\n", 7);
	return (num);
}

void	load_images(t_mlx *win, int img_width, int img_height)
{
	char	*relative_path_wall;
	char	*relative_path_character;

	relative_path_wall = "textures/wall.xpm";
	relative_path_character = "textures/character/CharacterRight.xpm";
	win->test_img = mlx_xpm_file_to_image(win->mlx, relative_path_wall,
			&img_width, &img_height);
	win->charcaterimg = mlx_xpm_file_to_image(win->mlx, relative_path_character,
			&img_width, &img_height);
}

void	init_structs(t_mlx *win)
{
	init_struct(win);
	init_struct2(win);
}

int	validate_map_size(char **map)
{
	int	width;
	int	height;

	width = strlen(map[0]);
	height = 0;
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

void	update_position(t_mlx *win, int key_code, char **arr)
{
	int	i;
	int	j;

	win->key_code = key_code;
	load_imagess(win);
	i = -1;
	while (arr[++i] != NULL)
	{
		j = -1;
		while (arr[i][++j] != '\0')
		{
			if (arr[i][j] == 'P')
			{
				check_exit(win, arr, i, j);
				move_character(win, arr, i, j);
				destroy_images(win);
				return ;
			}
		}
	}
}
