/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:53:16 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/17 15:04:17 by tlupu            ###   ########.fr       */
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

void	put_troop(t_mlx *win)
{
	int		i;
	int		image_width;
	int		image_height;
	char	*path[8];

	path[0] = "textures/enemy/enemy1.xpm";
	path[1] = "textures/enemy/enemy2.xpm";
	path[2] = "textures/enemy/enemy3.xpm";
	path[3] = "textures/enemy/enemy4.xpm";
	path[4] = "textures/enemy/enemy5.xpm";
	path[5] = "textures/enemy/enemy6.xpm";
	path[6] = "textures/enemy/enemy7.xpm";
	path[7] = "textures/enemy/enemy8.xpm";
	image_height = 64;
	image_width = 64;
	i = 0;
	while (i < 8)
	{
		win->enemy[i] = mlx_xpm_file_to_image(win->mlx, path[i], &image_width,
				&image_height);
		if (win->enemy[i] == NULL)
			return ;
		i++;
	}
}

void	display_bullet(t_mlx *win)
{
	int		i;
	int		image_width;
	int		image_height;
	char	*path[7];

	path[0] = "textures/bullet/bullet7.xpm";
	path[1] = "textures/bullet/bullet6.xpm";
	path[2] = "textures/bullet/bullet5.xpm";
	path[3] = "textures/bullet/bullet4.xpm";
	path[4] = "textures/bullet/bullet3.xpm";
	path[5] = "textures/bullet/bullet2.xpm";
	path[6] = "textures/bullet/bullet1.xpm";
	i = 0;
	while (i < 7)
	{
		win->bullet_img[i] = mlx_xpm_file_to_image(win->mlx, path[i],
				&image_width, &image_height);
		if (win->bullet_img[i] == NULL)
			return ;
		i++;
	}
}
