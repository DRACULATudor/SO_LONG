/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:57:33 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/10 15:50:01 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	char	*paths[8];

	paths[0] = "textures/coins/c1.xpm";
	paths[1] = "textures/coins/c2.xpm";
	paths[2] = "textures/coins/c3.xpm";
	paths[3] = "textures/coins/c4.xpm";
	paths[4] = "textures/coins/c5.xpm";
	paths[5] = "textures/coins/c6.xpm";
	paths[6] = "textures/coins/c7.xpm";
	paths[7] = "textures/coins/c8.xpm";
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
	relative_path_character = "textures/character/CharacterRight.xpm";
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

void	display_door(t_mlx *win)
{
	int		i;
	int		image_height;
	int		image_width;
	char	*path[5];

	path[0] = "textures/door/door1.xpm";
	path[1] = "textures/door/door2.xpm";
	path[2] = "textures/door/door3.xpm";
	path[3] = "textures/door/door4.xpm";
	path[4] = "textures/door/door5.xpm";
	i = 0;
	image_height = 64;
	image_width = 64;
	while (i < 5)
	{
		win->door_imgs[i] = mlx_xpm_file_to_image(win->mlx, path[i],
				&image_width, &image_height);
		if (win->coin_imgs[i] == NULL)
		{
			printf("Error loading image: %s\n", path[i]);
			return ;
		}
		i++;
	}
}

bool	check_for_colectables(t_mlx *win)
{
	int	i;
	int	j;

	i = 0;
	while (win->arr[i] != NULL)
	{
		j = 0;
		while (win->arr[i][j] != '\0')
		{
			if (win->arr[i][j] == 'C')
			{
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

int	get_p_x(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

int	get_p_y(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}
int	get_e_x(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

int	get_e_y(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int	get_b_y(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'B')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int	get_b_x(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'B')
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

void	put_troop(t_mlx *win)
{
	int		i;
	int		image_width;
	int		image_height;
	char	*path[8];

	path[0] = "textures/enemy/enemy1.xpm";
	path[1] = "textures/enemy/enemy2.xpm";
	path[2] = "textures/enemy/enemy3.xpm";
	path[3] = "textures/enemy/enemy4.xpm";
	path[4] = "textures/enemy/enemy5.xpm";
	path[5] = "textures/enemy/enemy6.xpm";
	path[6] = "textures/enemy/enemy7.xpm";
	path[7] = "textures/enemy/enemy8.xpm";
	image_height = 64;
	image_width = 64;
	i = 0;
	while (i < 8)
	{
		win->enemy[i] = mlx_xpm_file_to_image(win->mlx, path[i], &image_width,
				&image_height);
		if (win->enemy[i] == NULL)
		{
			printf("Error loading image: %s\n", path[i]);
			return ;
		}
		i++;
	}
}

void	display_bullet(t_mlx *win)
{
	int		i;
	int		image_width;
	int		image_height;
	char	*path[7];

	path[0] = "textures/bullet/bullet7.xpm";
	path[1] = "textures/bullet/bullet6.xpm";
	path[2] = "textures/bullet/bullet5.xpm";
	path[3] = "textures/bullet/bullet4.xpm";
	path[4] = "textures/bullet/bullet3.xpm";
	path[5] = "textures/bullet/bullet2.xpm";
	path[6] = "textures/bullet/bullet1.xpm";
	i = 0;
	while (i < 7)
	{
		win->bullet_img[i] = mlx_xpm_file_to_image(win->mlx, path[i],
				&image_width, &image_height);
		if (win->bullet_img[i] == NULL)
		{
			printf("Error loading image: %s\n", path[i]);
			return ;
		}
		i++;
	}
}

void	length(t_mlx *win)
{
	int	i;
	int	j;

	i = 0;
	while (win->arr[i] != NULL)
	{
		i++;
	}
	win->heng = i;
	j = 0;
	while (win->arr[0][j])
	{
		j++;
	}
	win->leng = j;
}

void	game_over(t_mlx *win)
{
	char			*path;
	int				image_width;
	int				image_height;
	long long int	i;
	int				center_x;
	int				center_y;

	i = 30000;
	win->over = true;
	path = "textures/gameover.xpm";
	image_width = 640;
	image_height = 360;
	win->over_img = mlx_xpm_file_to_image(win->mlx, path, &image_width,
			&image_height);
	mlx_clear_window(win->mlx, win->mlx_win);
	length(win);
	center_x = win->leng * 64 / 2 - image_width / 2;
	center_y = win->heng * 64 / 2 - image_height / 2;
	while (i > 0)
	{
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->over_img, center_x,
			center_y);
		i--;
	}
	mlx_loop_hook(win->mlx, NULL, NULL);
	exit(0);
}

int	bullet_shooting(t_mlx *win)
{
	int			i;
	int			j;
	static int	counter;
	static int	frame;
	static int	bullet_i = -1;
	static int	bullet_j = -1;
	static int	initial_i = -1;
	static int	initial_j = -1;

	i = 0;
	while (win->arr[i] != NULL)
	{
		j = 0;
		while (win->arr[i][j] != '\0')
		{
			if (win->arr[i][j] == 'B')
			{
				if (frame == 6)
				{
					if (win->arr[i][j - 1] == '0' && j > 0)
					{
						win->arr[i][j] = '0';
						win->arr[i][j - 1] = 'B';
						mlx_put_image_to_window(win->mlx, win->mlx_win,
							win->bullet_img[1], (j - 1) * 64, i * 64);
						frame = 0;
					}
					else if ((win->arr[i + 1][j] == 'P' || win->arr[i
							- 1][j] == 'P' || win->arr[i][j - 1] == 'P'
							|| win->arr[i][j + 1] == 'P') && j > 0)
					{
						game_over(win);
					}
					else
					{
						win->arr[i][j] = '0';
						win->arr[initial_i][initial_j] = 'B';
						mlx_put_image_to_window(win->mlx, win->mlx_win,
							win->bullet_img[0], initial_j * 64, initial_i * 64);
						frame = 0;
						win->wall = true;
					}
					if (win->over == false)
					{
						mlx_put_image_to_window(win->mlx, win->mlx_win,
							win->background_img, bullet_j * 64, bullet_i * 64);
					}
				}
				bullet_i = i;
				bullet_j = j;
				if (initial_i == -1 && initial_j == -1)
				{
					initial_i = i;
					initial_j = j;
				}
			}
			j++;
		}
		i++;
	}
	if (counter % 400 == 0 && win->exit == false)
	{
		frame = (frame + 1) % 7;
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->bullet_img[frame],
			bullet_j * 64, bullet_i * 64);
		counter = 0;
	}
	else if (win->exit == true && counter % 750 == 0)
	{
		frame = (frame + 1) % 7;
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->bullet_img[frame],
			bullet_j * 64, bullet_i * 64);
		counter = 0;
	}
	counter++;
	return (0);
}
int	display_troop(t_mlx *win)
{
	static int	counter = 0;
	static int	current_frame = 0;
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
			if (win->arr[i][j] == 'T')
			{
				mlx_put_image_to_window(win->mlx, win->mlx_win,
					win->enemy[current_frame], j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
	if (counter % 1500 == 0)
	{
		current_frame = (current_frame + 1) % 8;
		counter = 0;
	}
	counter++;
	return (0);
}

int	display_next_frame_and_door(t_mlx *win)
{
	static int	current_frame = 0;
	static int	door_frame = 0;
	static int	counter = 0;
	int			i;
	int			j;
	int			p_x;
	int			p_y;

	if (win == NULL || win->arr == NULL)
	{
		printf("Error: arr or win is NULL\n");
		return (1);
	}
	i = 0;
	while (win->arr[i] != NULL)
	{
		j = 0;
		p_x = get_e_x(win->arr);
		while (win->arr[i][j] != '\0')
		{
			p_y = get_e_y(win->arr);
			if (win->exit == true && p_x == i && p_y == j)
			{
				printf("Game Over: Reached Exit!\n");
				mlx_destroy_window(win->mlx, win->mlx_win);
				exit(0);
			}
			if (win->arr[i][j] == 'C')
			{
				mlx_put_image_to_window(win->mlx, win->mlx_win,
					win->coin_imgs[current_frame], j * 64, i * 64);
			}
			if (win->arr[i][j] == 'E' && door_frame <= 5)
			{
				mlx_put_image_to_window(win->mlx, win->mlx_win,
					win->door_imgs[door_frame], j * 64, i * 64);
				if (door_frame == 4)
				{
					win->exit = true;
					return (0);
				}
				if (win->arr[i][j] == 'T')
				{
					display_troop(win);
				}
			}
			j++;
		}
		i++;
	}
	if (counter % 1000 == 0)
	{
		current_frame = (current_frame + 1) % 8;
		if (check_for_colectables(win))
		{
			if (counter % 5 == 0)
			{
				door_frame = (door_frame + 1) % 5;
			}
		}
		if (!(check_for_colectables(win)))
			counter = 0;
	}
	counter++;
	return (0);
}

void	load_count(t_mlx *win)
{
	char	*move_count_str;
	char	*move_str;
	int		x;
	int		y;

	x = win->leng * 64;
	y = 0;
	while (y < 30)
	{
		x = win->leng * 64;
		while (x < win->leng * 64 + 200)
		{
			mlx_pixel_put(win->mlx, win->mlx_win, x, y, 0x654321);
			x++;
		}
		y++;
	}
	move_str = ft_itoa(win->count1122);
	move_count_str = ft_strjoin("Move count: ", move_str);
	mlx_string_put(win->mlx, win->mlx_win, win->leng * 64 + 10, 20, 0xFFFFFF,
		move_count_str);
	free(move_str);
	free(move_count_str);
}

void	update_position(t_mlx *win, int key_code, char **arr)
{
	int		i;
	int		j;
	int		img_width;
	int		img_height;
	char	*path_ml;
	char	*path_C;
	char	*path_r;

	i = 0;
	path_ml = "textures/character/CharacterMoreRight.xpm";
	path_r = "textures/character/CharacterLeft.xpm";
	path_C = "textures/character/CharacterCenter.xpm";
	img_height = 64;
	img_width = 64;
	win->character_img_l = mlx_xpm_file_to_image(win->mlx, path_ml, &img_width,
			&img_height);
	win->character_img_r = mlx_xpm_file_to_image(win->mlx, path_r, &img_width,
			&img_height);
	win->character_img_ur = mlx_xpm_file_to_image(win->mlx, path_C, &img_width,
			&img_height);
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (arr[i][j] == 'P')
			{
				if (key_code == A && j > 0 && arr[i][j - 1] != '1' && arr[i][j
					- 1] != 'T' && arr[i][j - 1] != 'B')
				{
					if (win->exit == false && arr[i][j - 1] != 'E')
					{
						arr[i][j] = '0';
						arr[i][j - 1] = 'P';
						mlx_put_image_to_window(win->mlx, win->mlx_win,
							win->background_img, j * 64, i * 64);
						mlx_put_image_to_window(win->mlx, win->mlx_win,
							win->character_img_l, (j - 1) * 64, i * 64);
					}
					else if (win->exit == true)
					{
						arr[i][j] = '0';
						arr[i][j - 1] = 'P';
						mlx_put_image_to_window(win->mlx, win->mlx_win,
							win->background_img, j * 64, i * 64);
						mlx_put_image_to_window(win->mlx, win->mlx_win,
							win->character_img_l, (j - 1) * 64, i * 64);
					}
					win->count1122 += 1;
					load_count(win);
					return ;
				}
				else if (key_code == D && j < (win->width - 1) && arr[i][j
					+ 1] != '1' && arr[i][j + 1] != 'T' && arr[i][j + 1] != 'B')
				{
					if (win->exit == false && arr[i][j + 1] != 'E')
					{
						arr[i][j] = '0';
						arr[i][j + 1] = 'P';
						mlx_put_image_to_window(win->mlx, win->mlx_win,
							win->background_img, j * 64, i * 64);
						mlx_put_image_to_window(win->mlx, win->mlx_win,
							win->character_img_r, (j + 1) * 64, i * 64);
					}
					else if (win->exit == true)
					{
						arr[i][j] = '0';
						arr[i][j + 1] = 'P';
						mlx_put_image_to_window(win->mlx, win->mlx_win,
							win->background_img, j * 64, i * 64);
						mlx_put_image_to_window(win->mlx, win->mlx_win,
							win->character_img_r, (j + 1) * 64, i * 64);
					}
					win->count1122 += 1;
					load_count(win);
					return ;
				}
				else if (key_code == S && arr[i + 1][j] != '1' && arr[i
					+ 1][j] != 'T' && arr[i + 1][j] != 'B')
				{
					if (win->exit == false && arr[i + 1][j] != 'E')
					{
						arr[i][j] = '0';
						arr[i + 1][j] = 'P';
						mlx_put_image_to_window(win->mlx, win->mlx_win,
							win->background_img, j * 64, i * 64);
						mlx_put_image_to_window(win->mlx, win->mlx_win,
							win->character_img_ur, j * 64, (i + 1) * 64);
					}
					else if (win->exit == true)
					{
						arr[i][j] = '0';
						arr[i + 1][j] = 'P';
						mlx_put_image_to_window(win->mlx, win->mlx_win,
							win->background_img, j * 64, i * 64);
						mlx_put_image_to_window(win->mlx, win->mlx_win,
							win->character_img_ur, j * 64, (i + 1) * 64);
					}
					win->count1122 += 1;
					load_count(win);
					return ;
				}
				else if (key_code == W && i > 0 && arr[i - 1][j] != '1' && arr[i
					- 1][j] != 'T' && arr[i - 1][j] != 'B')
				{
					if (win->exit == false && arr[i - 1][j] != 'E')
					{
						arr[i][j] = '0';
						arr[i - 1][j] = 'P';
						mlx_put_image_to_window(win->mlx, win->mlx_win,
							win->background_img, j * 64, i * 64);
						mlx_put_image_to_window(win->mlx, win->mlx_win,
							win->character_img_ur, j * 64, (i - 1) * 64);
					}
					else if (win->exit == true)
					{
						arr[i][j] = '0';
						arr[i - 1][j] = 'P';
						mlx_put_image_to_window(win->mlx, win->mlx_win,
							win->background_img, j * 64, i * 64);
						mlx_put_image_to_window(win->mlx, win->mlx_win,
							win->character_img_ur, j * 64, (i - 1) * 64);
					}
					win->count1122 += 1;
					load_count(win);
					return ;
				}
			}
			j++;
		}
		i++;
	}
}

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

void	fill(char **tab, t_point size, t_point begin, char to_fill[])
{
	char	c;
	int		i;

	if (begin.y < 0 || begin.y >= size.y || begin.x < 0 || begin.x >= size.x)
		return ;
	c = tab[begin.y][begin.x];
	i = 0;
	while (i < 5)
	{
		if (c == to_fill[i])
		{
			tab[begin.y][begin.x] = 'X';
			if (to_fill[i] == 'E')
				return ;
			fill(tab, size, (t_point){begin.x - 1, begin.y}, to_fill);
			fill(tab, size, (t_point){begin.x + 1, begin.y}, to_fill);
			fill(tab, size, (t_point){begin.x, begin.y - 1}, to_fill);
			fill(tab, size, (t_point){begin.x, begin.y + 1}, to_fill);
			break ;
		}
		i++;
	}
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

int	check_if_c_e_p_2(char **map2)
{
	int	i;
	int	j;

	i = 0;
	while (map2[i] != NULL)
	{
		j = 0;
		while (map2[i][j] != '\0')
		{
			if (map2[i][j] == 'P' || map2[i][j] == 'C' || map2[i][j] == 'E')
			{
				printf("Inavlid maasdas-<\n");
				free_arr(map2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_if_c_e_p(char **map2)
{
	int	i;
	int	j;

	i = 0;
	while (map2[i] != NULL)
	{
		j = 0;
		while (map2[i][j] != '\0')
		{
			if (map2[i][j] == 'P' || map2[i][j] == 'C' || map2[i][j] == 'E'
				|| map2[i][j] == 'T' || map2[i][j] == 'B')
			{
				printf("Inavlid map path :-<\n");
				free_arr(map2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_valid(char **map, int x, int y, int map_width, int map_height)
{
	t_point	size;
	int		i;
	int		valid;
	t_point	begin;
	char	to_fill[6];
	char	**map2;

	to_fill[0] = 'P';
	to_fill[1] = '0';
	to_fill[2] = 'C';
	to_fill[3] = 'E';
	to_fill[4] = 'T';
	to_fill[5] = 'B';
	size.x = map_width;
	size.y = map_height;
	i = 0;
	begin.x = x;
	begin.y = y;
	map2 = malloc(sizeof(char *) * (map_height + 1));
	while (i < map_height)
	{
		map2[i] = ft_strcpy(map2[i], map[i]);
		i++;
	}
	map2[i] = NULL;
	fill(map2, size, begin, to_fill);
	i = 0;
	valid = check_if_c_e_p_2(map2);
	return (valid);
}

int	check_map(char **map)
{
	int	x;
	int	y;
	int	valid;
	int	p_x;
	int	p_y;

	x = 0;
	y = 0;
	p_x = 0;
	p_y = 0;
	while (map[0][x])
		x++;
	while (map[y])
		y++;
	p_x = get_p_x(map);
	p_y = get_p_y(map);
	valid = check_valid(map, p_x, p_y, x, y);
	return (valid);
}

int	close_event(t_mlx *win)
{
	mlx_destroy_window(win->mlx, win->mlx_win);
	exit(0);
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
		return (1);
	return (0);
}

void	setup_mlx(t_mlx *win, char *relative_path)
{
	int	img_width;
	int	img_height;

	img_width = 64;
	img_height = 64;
	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, 64 * win->width, 64 * win->height,
			"So_Long");
	win->background_img = mlx_xpm_file_to_image(win->mlx, relative_path,
			&img_width, &img_height);
}

void	draw_background(t_mlx *win)
{
	int	i;
	int	j;

	i = 0;
	while (win->arr[i] != NULL)
	{
		j = 0;
		while (win->arr[i][j])
		{
			mlx_put_image_to_window(win->mlx, win->mlx_win, win->background_img,
				j * 64, i * 64);
			j++;
		}
		i++;
	}
	i--;
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->background_img, j * 64,
		i * 64);
}

int	display_all(t_mlx *win)
{
	display_next_frame_and_door(win);
	display_troop(win);
	bullet_shooting(win);
	return (0);
}

void	setup_hooks(t_mlx *win)
{
	mlx_loop_hook(win->mlx, display_all, win);
	mlx_key_hook(win->mlx_win, key_hook, (void *)win);
	mlx_hook(win->mlx_win, 17, 1L << 17, close_event, win);
}

int	main(int argc, char **argv)
{
	t_mlx	win;
	char	**arr;
	char	*relative_path;

	win.over = false;
	win.count1122 = 0;
	relative_path = "textures/Background.xpm";
	int valid, validate;
	if (validate_args(argc, argv, &win))
		return (1);
	arr = fill_map_arr(argv[1]);
	valid = check_map(arr);
	validate = validate_map_features(arr, &win);
	win.arr = arr;
	if (validate == 0 && valid == 1)
	{
		setup_mlx(&win, relative_path);
		if (win.background_img == NULL)
		{
			printf("Error loading image\n");
			return (1);
		}
		draw_background(&win);
		put_collectable(&win);
		display_door(&win);
		put_troop(&win);
		display_bullet(&win);
		get_cooridnates_sprts(arr, &win);
		setup_hooks(&win);
		load_count(&win);
		mlx_loop(win.mlx);
	}
	return (0);
}
