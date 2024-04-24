/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:01:12 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/24 16:43:41 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_left(t_mlx *win, char **arr, int i, int j)
{
	if (j > 0 && arr[i][j - 1] != '1' && arr[i][j - 1] != 'T' && arr[i][j
		- 1] != 'B')
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
		load_count(win);
		return ;
	}
}

void	move_right(t_mlx *win, char **arr, int i, int j)
{
	if (j < (win->width - 1) && arr[i][j + 1] != '1' && arr[i][j + 1] != 'T'
		&& arr[i][j + 1] != 'B')
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
		load_count(win);
		return ;
	}
}

void	move_up(t_mlx *win, char **arr, int i, int j)
{
	if (i > 0 && arr[i - 1][j] != '1' && arr[i - 1][j] != 'T' && arr[i
		- 1][j] != 'B')
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
		load_count(win);
		return ;
	}
}

void	move_down(t_mlx *win, char **arr, int i, int j)
{
	if (arr[i + 1][j] != '1' && arr[i + 1][j] != 'B' && arr[i + 1][j] != 'T')
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
		load_count(win);
		return ;
	}
}

void	move_player(t_mlx *win, char **arr, t_position pos, int key_code)
{
	if (key_code == A)
		move_left(win, arr, pos.i, pos.j);
	else if (key_code == D)
		move_right(win, arr, pos.i, pos.j);
	else if (key_code == S)
		move_down(win, arr, pos.i, pos.j);
	else if (key_code == W)
		move_up(win, arr, pos.i, pos.j);
}
