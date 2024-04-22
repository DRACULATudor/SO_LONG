/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:59:12 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/19 17:17:29 by tlupu            ###   ########.fr       */
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