/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:12:21 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/19 14:13:26 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_struct2(t_mlx *win)
{
	win->mlx = NULL;
	win->mlx_win = NULL;
	init_images(win);
	init_enemy_and_bullet(win);
	init_door_and_coin(win);
}

void	destroy_enemy_and_bullet(t_mlx *win)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (win->enemy[i])
		{
			mlx_destroy_image(win->mlx, win->enemy[i]);
			win->enemy[i] = NULL;
		}
		if (i < 7 && win->bullet_img[i])
		{
			mlx_destroy_image(win->mlx, win->bullet_img[i]);
			win->bullet_img[i] = NULL;
		}
		i++;
	}
}

void	destroy_door_and_coin(t_mlx *win)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (win->door_imgs[i])
		{
			mlx_destroy_image(win->mlx, win->door_imgs[i]);
			win->door_imgs[i] = NULL;
		}
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (win->coin_imgs[i])
		{
			mlx_destroy_image(win->mlx, win->coin_imgs[i]);
			win->coin_imgs[i] = NULL;
		}
		i++;
	}
}

void	destroy_image(t_mlx *win)
{
	if (win->charcaterimg)
		mlx_destroy_image(win->mlx, win->charcaterimg);
	if (win->character_img_l)
		mlx_destroy_image(win->mlx, win->character_img_l);
	if (win->character_img_r)
		mlx_destroy_image(win->mlx, win->character_img_r);
	if (win->character_img_ur)
		mlx_destroy_image(win->mlx, win->character_img_ur);
	if (win->background_img)
		mlx_destroy_image(win->mlx, win->background_img);
	if (win->colectableimg)
		mlx_destroy_image(win->mlx, win->colectableimg);
}

void	close_events(t_mlx *win)
{
	destroy_enemy_and_bullet(win);
	destroy_door_and_coin(win);
	destroy_image(win);
	if (win->mlx_win)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		win->mlx_win = NULL;
	}
	exit(0);
}
