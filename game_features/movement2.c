#include "../so_long.h"

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

void	load_image(t_mlx *win, void **img, char *path)
{
	int	img_width;
	int	img_height;

	img_width = 64;
	img_height = 64;
	if (*img)
	{
		mlx_destroy_image(win->mlx, *img);
		*img = NULL;
	}
	*img = mlx_xpm_file_to_image(win->mlx, path, &img_width, &img_height);
}

void	load_imagess(t_mlx *win)
{
	char	*path_ml;
	char	*path_r;
	char	*path_C;

	path_ml = "textures/character/CharacterMoreRight.xpm";
	path_r = "textures/character/CharacterLeft.xpm";
	path_C = "textures/character/CharacterCenter.xpm";
	load_image(win, &(win->character_img_l), path_ml);
	load_image(win, &(win->character_img_r), path_r);
	load_image(win, &(win->character_img_ur), path_C);
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
