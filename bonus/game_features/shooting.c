/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:25:41 by tlupu             #+#    #+#             */
/*   Updated: 2025/03/19 15:21:23 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_game_over(t_mlx *win, int i, int j)
{
	if ((win->arr[i][j - 1] == 'P' || win->arr[i][j + 1] == 'P') && j > 0)
		return (1);
	return (0);
}

void	reset_bullet_position(t_mlx *win, t_bullet *bullet)
{
	int	x;
	int	y;

	x = get_p_x(win->arr);
	y = get_p_y(win->arr);
	if (bullet->initial_i == y && bullet->initial_j == x)
		game_over(win);
	else
	{
		win->arr[bullet->bullet_i][bullet->bullet_j] = '0';
		win->arr[bullet->initial_i][bullet->initial_j] = 'B';
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->bullet_img[0],
			bullet->initial_j * 64, bullet->initial_i * 64);
		bullet->frame = 0;
		win->wall = true;
	}
}

void	handle_bullet_movement(t_mlx *win, int i, int j, t_bullet *bullet)
{
	if (win->arr[i][j] == 'B')
	{
		if (bullet->frame == 6)
		{
			if (win->arr[i][j - 1] == '0' && j > 0)
				update_bullet_position(win, i, j, &bullet->frame);
			else if (check_game_over(win, i, j) == 1)
				game_over(win);
			else
				reset_bullet_position(win, bullet);
			if (win->over == false)
				mlx_put_image_to_window(win->mlx, win->mlx_win,
					win->background_img, bullet->bullet_j * 64, bullet->bullet_i
					* 64);
		}
		bullet->bullet_i = i;
		bullet->bullet_j = j;
		if (bullet->initial_i == -1 && bullet->initial_j == -1)
		{
			bullet->initial_i = i;
			bullet->initial_j = j;
		}
	}
}

void	iterate_through_map(t_mlx *win, t_bullet *bullet)
{
	int	i;
	int	j;

	i = 0;
	while (win->arr[i] != NULL)
	{
		j = 0;
		while (win->arr[i][j] != '\0')
		{
			handle_bullet_movement(win, i, j, bullet);
			j++;
		}
		i++;
	}
}

int	bullet_shooting(t_mlx *win)
{
	static t_bullet	bullet;
	static int		initialized;

	if (!initialized)
	{
		init_bullet(&bullet);
		initialized = 1;
	}
	iterate_through_map(win, &bullet);
	if (bullet.counter % 170 == 0 && (win->exit == false || win->exit == true))
	{
		bullet.frame = (bullet.frame + 1) % 7;
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			win->bullet_img[bullet.frame], bullet.bullet_j * 64, bullet.bullet_i
			* 64);
		bullet.counter = 0;
	}
	bullet.counter++;
	return (0);
}
