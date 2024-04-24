/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:03:49 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/24 12:55:49 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_struct2(t_mlx *win)
{
	win->mlx = NULL;
	win->mlx_win = NULL;
	init_images(win);
	init_door_and_coin(win);
}

void	destroy_door_and_coin(t_mlx *win)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (win->door_imgs[i])
		{
			mlx_destroy_image(win->mlx, win->door_imgs[i]);
			win->door_imgs[i] = NULL;
		}
		i++;
	}
	i = 0;
	while (i < 7)
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
	destroy_door_and_coin(win);
	destroy_image(win);
	if (win->mlx_win)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		win->mlx_win = NULL;
	}
	exit(0);
}

void	count_map_features(char **arr, int *pande, int *c)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (arr[i][j] == 'E' || arr[i][j] == 'P')
				(*pande)++;
			else if (arr[i][j] == 'C')
				(*c)++;
			else if (arr[i][j] != 'E' && arr[i][j] != 'P' && arr[i][j] != 'C'
				&& arr[i][j] != '0' && arr[i][j] != '1' && arr[i][j] != '\n')
			{
				write(1, "Error\n", 7);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
