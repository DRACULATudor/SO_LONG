/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:11:49 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/19 14:13:35 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	count_map_features(char **arr, int *pande, int *c, int *enemy)
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
			else if (arr[i][j] == 'T' || arr[i][j] == 'B')
				(*enemy)++;
			if (arr[i][j] == 'T' && arr[i][j - 1] != 'B')
				return ;
			j++;
		}
		i++;
	}
}

void	init_struct(t_mlx *win)
{
	win->map2 = NULL;
	win->dor_y = 0;
	win->dor_x = 0;
	win->width = 0;
	win->height = 0;
	win->special_key = 0;
	win->x = 0;
	win->bullet_x = 0;
	win->bullet_y = 0;
	win->leng = 0;
	win->count1122 = 0;
	win->heng = 0;
	win->y = 0;
	win->over = false;
	win->path = false;
	win->number = false;
	win->wall = false;
	win->exit = false;
	win->flag = false;
	win->isd = false;
	win->is_bullet_active = false;
	win->arr = NULL;
}

void	init_images(t_mlx *win)
{
	win->bullet = NULL;
	win->test_img = NULL;
	win->charcaterimg = NULL;
	win->character_img_l = NULL;
	win->character_img_r = NULL;
	win->character_img_ur = NULL;
	win->over_img = NULL;
	win->colectableimg = NULL;
	win->background_img = NULL;
}

void	init_enemy_and_bullet(t_mlx *win)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		win->enemy[i] = NULL;
		if (i < 7)
			win->bullet_img[i] = NULL;
		i++;
	}
}

void	init_door_and_coin(t_mlx *win)
{
	int	i;

	i = -1;
	while (++i < 6)
		win->door_imgs[i] = NULL;
	i = -1;
	while (++i < 8)
		win->coin_imgs[i] = NULL;
}
