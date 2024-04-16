/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:25:41 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/16 14:25:14 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_game_over(t_mlx *win, int i, int j)
{
	if ((win->arr[i + 1][j] == 'P' || win->arr[i - 1][j] == 'P' || win->arr[i][j
			- 1] == 'P' || win->arr[i][j + 1] == 'P') && j > 0)
	{
		game_over(win);
	}
}

void	reset_bullet_position(t_mlx *win, int i, int j, int *initial_i,
		int *initial_j, int *frame)
{
	win->arr[i][j] = '0';
	win->arr[*initial_i][*initial_j] = 'B';
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bullet_img[0],
		*initial_j * 64, *initial_i * 64);
	*frame = 0;
	win->wall = true;
}

void	handle_bullet_movement(t_mlx *win, int i, int j, int *bullet_i,
		int *bullet_j, int *initial_i, int *initial_j, int *frame)
{
	if (win->arr[i][j] == 'B')
	{
		if (*frame == 6)
		{
			if (win->arr[i][j - 1] == '0' && j > 0)
				update_bullet_position(win, i, j, frame);
			else
			{
				check_game_over(win, i, j);
				reset_bullet_position(win, i, j, initial_i, initial_j, frame);
			}
			if (win->over == false)
				mlx_put_image_to_window(win->mlx, win->mlx_win,
					win->background_img, *bullet_j * 64, *bullet_i * 64);
		}
		*bullet_i = i;
		*bullet_j = j;
		if (*initial_i == -1 && *initial_j == -1)
		{
			*initial_i = i;
			*initial_j = j;
		}
	}
}

void	iterate_through_map(t_mlx *win, int *bullet_i, int *bullet_j,
		int *initial_i, int *initial_j, int *frame)
{
	int	i;
	int	j;

	i = 0;
	while (win->arr[i] != NULL)
	{
		j = 0;
		while (win->arr[i][j] != '\0')
		{
			handle_bullet_movement(win, i, j, bullet_i, bullet_j, initial_i,
				initial_j, frame);
			j++;
		}
		i++;
	}
}

int	bullet_shooting(t_mlx *win)
{
	static int	counter;
	static int	frame = 0;
	static int	bullet_i = -1;
	static int	bullet_j = -1;
	static int	initial_i = -1;
	static int	initial_j = -1;

	iterate_through_map(win, &bullet_i, &bullet_j, &initial_i, &initial_j,
		&frame);
	if (counter % 700 == 0 && win->exit == false)
	{
		frame = (frame + 1) % 7;
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->bullet_img[frame],
			bullet_j * 64, bullet_i * 64);
		counter = 0;
	}
	else if (win->exit == true && counter % 880 == 0)
	{
		frame = (frame + 1) % 7;
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->bullet_img[frame],
			bullet_j * 64, bullet_i * 64);
		counter = 0;
	}
	counter++;
	return (0);
}
