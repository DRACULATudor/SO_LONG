/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:27:26 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/22 15:35:36 by tlupu            ###   ########.fr       */
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

int	key_press(int keycode, t_mlx *win)
{
	if (keycode == ESC)
	{
		close_event(win);
		exit(0);
	}
	return (0);
}

void	init_structs(t_mlx *win)
{
	init_struct(win);
	init_struct2(win);
}

void	kill_player(t_mlx *win, int keycode)
{
	int	i;
	int	j;

	i = -1;
	while (win->arr[++i] != NULL)
	{
		j = -1;
		while (win->arr[i][++j] != '\0')
		{
			if (win->arr[i][j] == 'P')
			{
				if ((keycode == W && i > 0 && win->arr[i - 1][j] == 'T')
					|| (keycode == A && j > 0 && win->arr[i][j - 1] == 'T')
					|| (keycode == S && win->arr[i + 1] != NULL && win->arr[i
						+ 1][j] == 'T') || (keycode == D && win->arr[i][j
						+ 1] != '\0' && win->arr[i][j + 1] == 'T'))
				{
					game_over(win);
				}
			}
		}
	}
}

void	update_position(t_mlx *win, int key_code, char **arr)
{
	t_position	pos;

	load_imagess(win);
	pos.i = -1;
	while (arr[++pos.i] != NULL)
	{
		pos.j = -1;
		while (arr[pos.i][++pos.j] != '\0')
		{
			if (arr[pos.i][pos.j] == 'P' && !win->over)
			{
				if (arr[pos.i][pos.j] == 'P' && win->exit && (arr[pos.i][pos.j - 1] == 'E'
						|| arr[pos.i][pos.j + 1] == 'E' || arr[pos.i + 1][pos.j] == 'E' || arr[pos.i
						- 1][pos.j] == 'E'))
				{
					close_event(win);
					exit(1);
				}
				move_player(win, arr, pos, key_code);
				destroy_images(win);
				kill_player(win, key_code);
				return ;
			}
		}
	}
}
