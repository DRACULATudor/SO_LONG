/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move_charact.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:45:53 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/17 16:10:49 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	destroy_images(t_mlx *win)
{
	if (win->character_img_l)
	{
		mlx_destroy_image(win->mlx, win->character_img_l);
		win->character_img_l = NULL;
	}
	if (win->character_img_r)
	{
		mlx_destroy_image(win->mlx, win->character_img_r);
		win->character_img_r = NULL;
	}
	if (win->character_img_ur)
	{
		mlx_destroy_image(win->mlx, win->character_img_ur);
		win->character_img_ur = NULL;
	}
}

void	move_left(t_mlx *win, char **arr, int i, int j)
{
	if (j > 0 && arr[i][j - 1] != '1')
	{
		if (win->exit == false && arr[i][j - 1] != 'E')
		{
			arr[i][j] = '0';
			arr[i][j - 1] = 'P';
			mlx_put_image_to_window(win->mlx, win->mlx_win, win->background_img,
				j * 64, i * 64);
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				win->character_img_l, (j - 1) * 64, i * 64);
		}
		else if (win->exit == true)
		{
			arr[i][j] = '0';
			arr[i][j - 1] = 'P';
			mlx_put_image_to_window(win->mlx, win->mlx_win, win->background_img,
				j * 64, i * 64);
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				win->character_img_l, (j - 1) * 64, i * 64);
		}
		win->count1122 += 1;
		return ;
	}
}

void	move_right(t_mlx *win, char **arr, int i, int j)
{
	if (j < (win->width - 1) && arr[i][j + 1] != '1')
	{
		if (win->exit == false && arr[i][j + 1] != 'E')
		{
			arr[i][j] = '0';
			arr[i][j + 1] = 'P';
			mlx_put_image_to_window(win->mlx, win->mlx_win, win->background_img,
				j * 64, i * 64);
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				win->character_img_r, (j + 1) * 64, i * 64);
		}
		else if (win->exit == true)
		{
			arr[i][j] = '0';
			arr[i][j + 1] = 'P';
			mlx_put_image_to_window(win->mlx, win->mlx_win, win->background_img,
				j * 64, i * 64);
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				win->character_img_r, (j + 1) * 64, i * 64);
		}
		win->count1122 += 1;
		return ;
	}
}

void	move_up(t_mlx *win, char **arr, int i, int j)
{
	if (i > 0 && arr[i - 1][j] != '1')
	{
		if (win->exit == false && arr[i - 1][j] != 'E')
		{
			arr[i][j] = '0';
			arr[i - 1][j] = 'P';
			mlx_put_image_to_window(win->mlx, win->mlx_win, win->background_img,
				j * 64, i * 64);
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				win->character_img_ur, j * 64, (i - 1) * 64);
		}
		else if (win->exit == true)
		{
			arr[i][j] = '0';
			arr[i - 1][j] = 'P';
			mlx_put_image_to_window(win->mlx, win->mlx_win, win->background_img,
				j * 64, i * 64);
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				win->character_img_ur, j * 64, (i - 1) * 64);
		}
		win->count1122 += 1;
		return ;
	}
}

void	move_down(t_mlx *win, char **arr, int i, int j)
{
	if (arr[i + 1][j] != '1')
	{
		if (win->exit == false && arr[i + 1][j] != 'E')
		{
			arr[i][j] = '0';
			arr[i + 1][j] = 'P';
			mlx_put_image_to_window(win->mlx, win->mlx_win, win->background_img,
				j * 64, i * 64);
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				win->character_img_ur, j * 64, (i + 1) * 64);
		}
		else if (win->exit == true)
		{
			arr[i][j] = '0';
			arr[i + 1][j] = 'P';
			mlx_put_image_to_window(win->mlx, win->mlx_win, win->background_img,
				j * 64, i * 64);
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				win->character_img_ur, j * 64, (i + 1) * 64);
		}
		win->count1122 += 1;
		return ;
	}
}

void	update_position(t_mlx *win, int key_code, char **arr)
{
	int	i;
	int	j;

	load_imagess(win);
	i = -1;
	while (arr[++i] != NULL)
	{
		j = -1;
		while (arr[i][++j] != '\0')
		{
			if (arr[i][j] == 'P')
			{
				if (key_code == A)
					move_left(win, arr, i, j);
				else if (key_code == D)
					move_right(win, arr, i, j);
				else if (key_code == S)
					move_down(win, arr, i, j);
				else if (key_code == W)
					move_up(win, arr, i, j);
				destroy_images(win);
				return ;
			}
		}
	}
}