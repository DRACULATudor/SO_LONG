/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:21:48 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/19 14:29:52 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	validate_window_and_array(t_mlx *win)
{
	if (win == NULL || win->arr == NULL)
	{
		printf("Error: arr or win is NULL\n");
		return (1);
	}
	return (0);
}

void	display_elements(t_mlx *win, int i, int j, int *frames)
{
	int	p_x;
	int	p_y;

	p_x = get_e_x(win->arr);
	p_y = get_e_y(win->arr);
	if (win->exit == true && p_x == i && p_y == j)
	{
		close_events(win);
		exit(0);
	}
	if (win->arr[i][j] == 'C')
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			win->coin_imgs[frames[0]], j * 64, i * 64);
	if (win->arr[i][j] == 'E' && frames[1] <= 5)
	{
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			win->door_imgs[frames[1]], j * 64, i * 64);
		if (frames[1] == 4)
		{
			win->exit = true;
			return ;
		}
		if (win->arr[i][j] == 'T')
			display_troop(win);
	}
}

void	update_frames_and_counter(t_mlx *win, int *frames, int *counter)
{
	if (*counter % 750 == 0)
	{
		frames[0] = (frames[0] + 1) % 8;
		if (check_for_colectables(win) && !win->exit)
		{
			if (*counter % 5 == 0)
				frames[1] = (frames[1] + 1) % 5;
		}
		if (!(check_for_colectables(win)))
			*counter = 0;
	}
	(*counter)++;
}

int	display_next_frame_and_door(t_mlx *win)
{
	static int	frames[2];
	static int	counter;
	int			i;
	int			j;

	if (validate_window_and_array(win))
		return (1);
	i = 0;
	while (win->arr[i] != NULL)
	{
		j = 0;
		while (win->arr[i][j] != '\0')
		{
			display_elements(win, i, j, frames);
			j++;
		}
		i++;
	}
	update_frames_and_counter(win, frames, &counter);
	return (0);
}
