/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:49:41 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/17 15:54:38 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	key_hook(int key_code, t_mlx *win)
{
	static int	count;

	if (!win)
	{
		return (0);
	}
	count = 0;
	if (key_code == A || key_code == W || key_code == S || key_code == D)
	{
		win->key_release = key_code;
		update_position(win, key_code, win->arr);
	}
	count++;
	return (0);
}

int close_event(t_mlx *win)
{
    mlx_destroy_window(win->mlx, win->mlx_win);
    exit(0);
}

void	setup_mlx(t_mlx *win)
{
	int		img_width;
	int		img_height;
	char	*relative_path;

	relative_path = "textures/Background.xpm";
	img_width = 64;
	img_height = 64;
	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, 64 * win->width, 64 * win->height,
			"So_Long");
	win->background_img = mlx_xpm_file_to_image(win->mlx, relative_path,
			&img_width, &img_height);
}

void setup_hooks(t_mlx *win)
{
    mlx_loop_hook(win->mlx, display_next_frame_and_door, win);
    mlx_key_hook(win->mlx_win, key_hook, (void *)win);
    mlx_hook(win->mlx_win, 17, 1L<<17, close_event, win);
}