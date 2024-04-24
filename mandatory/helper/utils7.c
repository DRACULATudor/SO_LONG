/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:41:32 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/24 17:19:14 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_exit(t_mlx *win, char **arr, int i, int j)
{
	if (arr[i][j] == 'P' && win->exit)
	{
		if ((win->key_code == A && arr[i][j - 1] == 'E') || (win->key_code == D
				&& arr[i][j + 1] == 'E') || (win->key_code == S && arr[i
				+ 1][j] == 'E') || (win->key_code == W && arr[i - 1][j] == 'E'))
		{
			close_event(win);
			exit(1);
		}
	}
}

void	display_cin(t_mlx *win, int i, int j, int *current_frame)
{
	if (win->arr[i][j] == 'C')
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			win->coin_imgs[*current_frame], j * 64, i * 64);
}
