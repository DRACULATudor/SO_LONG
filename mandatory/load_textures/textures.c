/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:23:05 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/17 15:24:59 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	put_collectable(t_mlx *win)
{
	int		i;
	int		img_width;
	int		img_height;
	char	*paths[8];

	paths[0] = "textures/coins/c1.xpm";
	paths[1] = "textures/coins/c2.xpm";
	paths[2] = "textures/coins/c3.xpm";
	paths[3] = "textures/coins/c4.xpm";
	paths[4] = "textures/coins/c5.xpm";
	paths[5] = "textures/coins/c6.xpm";
	paths[6] = "textures/coins/c7.xpm";
	paths[7] = "textures/coins/c8.xpm";
	img_width = 64;
	img_height = 64;
	i = 0;
	while (i < 8)
	{
		win->coin_imgs[i] = mlx_xpm_file_to_image(win->mlx, paths[i],
				&img_width, &img_height);
		if (win->coin_imgs[i] == NULL)
			return ;
		i++;
	}
}

void	display_door(t_mlx *win)
{
	int		i;
	int		image_height;
	int		image_width;
	char	*path[5];

	path[0] = "textures/door/door1.xpm";
	path[1] = "textures/door/door2.xpm";
	path[2] = "textures/door/door3.xpm";
	path[3] = "textures/door/door4.xpm";
	path[4] = "textures/door/door5.xpm";
	i = 0;
	image_height = 64;
	image_width = 64;
	while (i < 5)
	{
		win->door_imgs[i] = mlx_xpm_file_to_image(win->mlx, path[i],
				&image_width, &image_height);
		if (win->coin_imgs[i] == NULL)
			return ;
		i++;
	}
}

void	load_image(t_mlx *win, void **img, char *path)
{
	int	img_width;
	int	img_height;

	img_width = 64;
	img_height = 64;
	if (*img)
	{
		mlx_destroy_image(win->mlx, *img);
		*img = NULL;
	}
	*img = mlx_xpm_file_to_image(win->mlx, path, &img_width, &img_height);
}

void	load_imagess(t_mlx *win)
{
	char	*path_ml;
	char	*path_r;
	char	*path_C;

	path_ml = "textures/character/CharacterMoreRight.xpm";
	path_r = "textures/character/CharacterLeft.xpm";
	path_C = "textures/character/CharacterCenter.xpm";
	load_image(win, &(win->character_img_l), path_ml);
	load_image(win, &(win->character_img_r), path_r);
	load_image(win, &(win->character_img_ur), path_C);
}
