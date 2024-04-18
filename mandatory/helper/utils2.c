/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:52:06 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/17 16:04:36 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	dst = malloc(sizeof(char) * ft_strlen(src) + 1);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
void	init_struct(t_mlx *win)
{
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
	win->last_row = 0;
	win->last_col = 0;
	win->key_release = 0;
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

void	init_door_and_coin(t_mlx *win)
{
	int	i = 0;

	while (i < 7)
	{
		win->coin_imgs[i] = NULL;
		if (i < 5)
			win->door_imgs[i] = NULL;
		i++;
	}
}



