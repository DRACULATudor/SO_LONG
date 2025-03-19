/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:18:11 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/24 21:11:27 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**error_fctc(int num)
{
	num = 1;
	write(2, "Error\n", 7);
	num = num - 1;
	exit(1);
}

char	**allocate_new_arr(char **arr, int i)
{
	char	**new_arr;

	new_arr = malloc(sizeof(char *) * (i + 2));
	if (new_arr == NULL)
		return (error_fctc(1));
	if (arr != NULL)
	{
		ft_memcpy(new_arr, arr, sizeof(char *) * (i));
		free(arr);
	}
	return (new_arr);
}

char	**fill_map_arr(char *filename)
{
	char	**arr;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	i = 0;
	arr = NULL;
	filename = get_next_line(fd);
	if (fd == -1 || fd == 0 || filename == NULL)
		return (error_fctc(1));
	while (filename != NULL)
	{
		arr = allocate_new_arr(arr, i);
		if (arr == NULL)
			return (NULL);
		arr[i] = filename;
		arr[i + 1] = NULL;
		i++;
		filename = get_next_line(fd);
	}
	close(fd);
	return (arr);
}

void	draw_map(char **arr, t_mlx *win)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (arr[i][j] == '1')
			{
				mlx_put_image_to_window(win->mlx, win->mlx_win, win->test_img, j
					* 64, i * 64);
			}
			if (arr[i][j] == 'P')
			{
				mlx_put_image_to_window(win->mlx, win->mlx_win,
					win->charcaterimg, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	get_cooridnates_sprts(char **arr, t_mlx *win)
{
	int	img_width;
	int	img_height;

	if (arr == NULL || win == NULL)
		return ;
	img_height = 64;
	img_width = 64;
	load_images(win, img_width, img_height);
	if (win->test_img == NULL || win->charcaterimg == NULL)
		return ;
	draw_map(arr, win);
}
