/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:57:33 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/29 15:48:44 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_features_custom(char **arr)
{
	int	i;
	int	j;
	int	pande;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	pande = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (arr[i][j] == 'E' || arr[i][j] == 'P')
				pande++;
			else if (arr[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (pande != 2)
	{
		printf("Invalid elements\n");
		return (1);
	}
	if (c < 1)
	{
		printf("Invalid elements\n");
		return (1);
	}
	return (0);
}

int	validate_map_element(char **arr, t_mlx *win)
{
	int	i;
	int	valid;
	int	j;
	int	last_row_index;
	int	last_column_index;

	i = 0;
	j = 0;
	last_row_index = 0;
	last_column_index = 0;
	while (arr[0][j] != '\0')
	{
		last_column_index = j;
		j++;
	}
	j--;
	win->width = j;
	last_column_index--;
	while (arr[i] != NULL)
	{
		last_row_index = i;
		i++;
	}
	win->height = last_row_index + 1;
	j = 0;
	while (j <= last_column_index)
	{
		if (arr[0][j] != '1' || arr[last_row_index][j] != '1')
		{
			printf("height is %d\n Last com %d\n j is %i, %c %c", win->height,
				last_row_index, j, arr[0][j], arr[last_row_index][j]);
			printf("Error ->WrongWall\n");
			return (1);
		}
		j++;
	}
	i = 0;
	while (i <= last_row_index)
	{
		if (arr[i][0] != '1' || arr[i][last_column_index] != '1')
		{
			printf("Error ->WrongWall\n");
			return (1);
		}
		i++;
	}
	valid = validate_map_features_custom(arr);
	return (valid);
}

int	validate_map_features(char **arr, t_mlx *win)
{
	int	i;
	int	j;
	int	len;
	int	valid;

	i = 0;
	len = -1;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\n' && arr[i][j] != '\0')
		{
			j++;
		}
		if (len == -1)
			len = j;
		else if (len != j)
		{
			printf("Error ->Invalid map\n");
			return (1);
		}
		i++;
	}
	valid = validate_map_element(arr, win);
	return (valid);
}

char	**fill_map_arr(char *filename)
{
	char	**arr;
	char	**new_arr;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	i = 0;
	arr = NULL;
	if (fd == -1)
	{
		printf("Error\n");
		return (NULL);
	}
	filename = get_next_line(fd);
	if (fd == -1 || fd == 0 || filename == NULL)
	{
		printf("Error\n");
		return (NULL);
	}
	while (filename != NULL)
	{
		new_arr = malloc(sizeof(char *) * (i + 2));
		if (new_arr == NULL)
		{
			printf("Error\n");
			return (NULL);
		}
		if (arr != NULL)
		{
			ft_memcpy(new_arr, arr, sizeof(char *) * (i));
			free(arr);
		}
		arr = new_arr;
		arr[i] = filename;
		arr[i + 1] = NULL;
		i++;
		filename = get_next_line(fd);
	}
	close(fd);
	return (arr);
}

void	put_collectable(t_mlx *win)
{
	int		i;
	int		img_width;
	int		img_height;
	char	*paths[8] = {"textures/coins/c1.xpm", "textures/coins/c2.xpm",
			"textures/coins/c3.xpm", "textures/coins/c4.xpm",
			"textures/coins/c5.xpm", "textures/coins/c6.xpm",
			"textures/coins/c7.xpm", "textures/coins/c8.xpm"};

	img_width = 64;
	img_height = 64;
	i = 0;
	while (i < 8)
	{
		win->coin_imgs[i] = mlx_xpm_file_to_image(win->mlx, paths[i],
				&img_width, &img_height);
		if (win->coin_imgs[i] == NULL)
		{
			printf("Error loading image: %s\n", paths[i]);
			return ;
		}
		i++;
	}
}

int	display_next_frame(t_mlx *win)
{
	static int	current_frame = 0;
	static int	counter = 0;
	int			i;
	int			j;

	if (win == NULL || win->arr == NULL)
	{
		printf("Error: arr or win is NULL\n");
		return (1);
	}
	i = 0;
	
	while (win->arr[i] != NULL)
	{
		j = 0;
		while (win->arr[i][j] != '\0')
		{
			if (win->arr[i][j] == 'C')
			{
				mlx_put_image_to_window(win->mlx, win->mlx_win,
					win->coin_imgs[current_frame], j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
	if (counter % 2500 == 0)
	{
		current_frame = (current_frame + 1) % 8;
		counter = 0;
	}
	counter++;
	return (0);
}

void	get_cooridnates_sprts(char **arr, t_mlx *win)
{
	int		i;
	int		j;
	int		img_width;
	int		img_height;
	char	*relative_path_character;
	char	*relative_path_wall;

	if (arr == NULL || win == NULL)
	{
		printf("Error: arr or444444 win is NULL\n");
		return ;
	}
	i = 0;
	relative_path_wall = "textures/wall.xpm";
	relative_path_character = "textures/Character.xpm";
	img_height = 64;
	img_width = 64;
	win->test_img = mlx_xpm_file_to_image(win->mlx, relative_path_wall,
			&img_width, &img_height);
	win->charcaterimg = mlx_xpm_file_to_image(win->mlx, relative_path_character,
			&img_width, &img_height);
	if (win->test_img == NULL || win->charcaterimg == NULL)
	{
		printf("Error loading image\n");
		return ;
	}
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

int	main(int argc, char **argv)
{
	int		j;
	int		i;
	char	**arr;
	t_mlx	win;
	int		validate;
	char	*relative_path;
	int		img_width;
	int		img_height;

	if (argc != 2)
		return (1);
	i = ft_strleng(argv[1]);
	if (i < 4 || (argv[1][i - 4] != '.' || argv[1][i - 3] != 'b' || argv[1][i
			- 2] != 'e' || argv[1][i - 1] != 'r'))
		return (1);
	arr = fill_map_arr(argv[1]);
	validate = validate_map_features(arr, &win);
	relative_path = "textures/Background.xpm";
	img_width = 64;
	img_height = 64;
	if (validate == 0)
	{
		i = 0;
		win.mlx = mlx_init();
		win.mlx_win = mlx_new_window(win.mlx, 64 * win.width, 64 * win.height,
				"So_Long");
		win.test_img = mlx_xpm_file_to_image(win.mlx, relative_path, &img_width,
				&img_height);
		if (win.test_img == NULL)
		{
			printf("Error loading image\n");
			return (1);
		}
		while (arr[i] != NULL)
		{
			j = 0;
			while (arr[i][j])
			{
				mlx_put_image_to_window(win.mlx, win.mlx_win, win.test_img, j
					* 64, i * 64);
				j++;
			}
			i++;
		}
		i--;
		mlx_put_image_to_window(win.mlx, win.mlx_win, win.test_img, j * 64, i
			* 64);
		put_collectable(&win);
		win.arr = arr;
		get_cooridnates_sprts(arr, &win);
		mlx_loop_hook(win.mlx, display_next_frame, &win);
		mlx_loop(win.mlx);
	}
	return (0);
}
