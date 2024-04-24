/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:35:57 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/24 19:40:07 by tlupu            ###   ########.fr       */
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

int	validate_args(int argc, char **argv, t_mlx *win)
{
	int	i;

	if (argc != 2)
		return (1);
	win->exit = false;
	i = ft_strleng(argv[1]);
	if (i < 4 || (argv[1][i - 4] != '.' || argv[1][i - 3] != 'b' || argv[1][i
			- 2] != 'e' || argv[1][i - 1] != 'r'))
		return (error_fct(1));
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*sour;
	char	*dest;
	size_t	i;

	sour = (char *)src;
	dest = (char *)dst;
	if (sour > dest)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = sour[i];
			i++;
		}
	}
	else if (sour < dest)
	{
		i = len;
		while (i > 0)
		{
			dest[i - 1] = sour[i - 1];
			i--;
		}
	}
	return (dst);
}

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	return (ft_memmove(dst, src, len));
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
