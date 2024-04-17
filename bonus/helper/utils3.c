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

void	init_enemy_and_bullet(t_mlx *win)
{
	int	i = 0;

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
	int	i = -1;

	while (++i < 6)
		win->door_imgs[i] = NULL;
	i = -1;
	while (++i < 8)
		win->coin_imgs[i] = NULL;
}

void	init_struct2(t_mlx *win)
{
	win->mlx = NULL;
	win->mlx_win = NULL;
	init_images(win);
	init_enemy_and_bullet(win);
	init_door_and_coin(win);
}

void	destroy_enemy_and_bullet(t_mlx *win)
{
	int	i = 0;

	while (i < 8)
	{
		if (win->enemy[i])
		{
			mlx_destroy_image(win->mlx, win->enemy[i]);
			win->enemy[i] = NULL;
		}
		if (i < 7 && win->bullet_img[i])
		{
			mlx_destroy_image(win->mlx, win->bullet_img[i]);
			win->bullet_img[i] = NULL;
		}
		i++;
	}
}

void	destroy_door_and_coin(t_mlx *win)
{
	int	i = 0;

	while (i < 6)
	{
		if (win->door_imgs[i])
		{
			mlx_destroy_image(win->mlx, win->door_imgs[i]);
			win->door_imgs[i] = NULL;
		}
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (win->coin_imgs[i])
		{
			mlx_destroy_image(win->mlx, win->coin_imgs[i]);
			win->coin_imgs[i] = NULL;
		}
		i++;
	}
}

void	destroy_image(t_mlx *win)
{
	if (win->charcaterimg)
		mlx_destroy_image(win->mlx, win->charcaterimg);
	if (win->character_img_l)
		mlx_destroy_image(win->mlx, win->character_img_l);
	if (win->character_img_r)
		mlx_destroy_image(win->mlx, win->character_img_r);
	if (win->character_img_ur)
		mlx_destroy_image(win->mlx, win->character_img_ur);
	if (win->background_img)
		mlx_destroy_image(win->mlx, win->background_img);
	if (win->colectableimg)
		mlx_destroy_image(win->mlx, win->colectableimg);
}

void	close_events(t_mlx *win)
{
	destroy_enemy_and_bullet(win);
	destroy_door_and_coin(win);
	destroy_image(win);
	if (win->mlx_win)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		win->mlx_win = NULL;
	}
	exit(0);
}