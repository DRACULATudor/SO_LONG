/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_disp_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:40:04 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/24 16:24:06 by tlupu            ###   ########.fr       */
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

void	display_dor(t_mlx *win, int i, int j, int door_frame)
{
	if (win->arr[i][j] == 'E' && door_frame <= 5)
	{
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			win->door_imgs[door_frame], j * 64, i * 64);
		if (door_frame == 4)
		{
			win->exit = true;
			return ;
		}
	}
}

void	display_elements(t_mlx *win, int i, int j, t_frames *frames)
{
	display_cin(win, i, j, &frames->current_frame);
	display_dor(win, i, j, frames->door_frame);
}

void	update_frames_and_counter(t_mlx *win, t_frames *frames, int *counter)
{
	if (*counter % 1000 == 0)
	{
		frames->current_frame = (frames->current_frame + 1) % 8;
		if (check_for_colectables(win) && !win->exit)
		{
			if (*counter % 5 == 0)
				frames->door_frame = (frames->door_frame + 1) % 5;
		}
		if (!(check_for_colectables(win)))
			*counter = 0;
	}
	(*counter)++;
}

int	display_next_frame_and_door(t_mlx *win)
{
	static t_frames	frames = {0, 0};
	static int		counter = 0;
	int				i;
	int				j;

	if (validate_window_and_array(win))
		return (1);
	i = 0;
	while (win->arr[i] != NULL)
	{
		j = 0;
		while (win->arr[i][j] != '\0')
		{
			display_elements(win, i, j, &frames);
			j++;
		}
		i++;
	}
	update_frames_and_counter(win, &frames, &counter);
	return (0);
}
