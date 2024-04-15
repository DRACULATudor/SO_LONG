/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:13:51 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/11 17:41:43 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void load_and_clear(t_mlx *win, int *center_x, int *center_y)
{
    char *path = "textures/gameover.xpm";
    int image_width = 640;
    int image_height = 360;

    win->over_img = mlx_xpm_file_to_image(win->mlx, path, &image_width, &image_height);
    mlx_clear_window(win->mlx, win->mlx_win);
    length(win);
    *center_x = win->leng * 64 / 2 - image_width / 2;
    *center_y = win->heng * 64 / 2 - image_height / 2;
}

void game_over(t_mlx *win)
{
    long long int i;
    int center_x;
    int center_y;

    i = 30000;
    win->over = true;
    load_and_clear(win, &center_x, &center_y);
    while (i > 0)
    {
        mlx_put_image_to_window(win->mlx, win->mlx_win, win->over_img, center_x, center_y);
        i--;
    }
    mlx_loop_hook(win->mlx, NULL, NULL);
    exit(0);
}

void display_troop_image(t_mlx *win, int current_frame)
{
    int i;
    int j;

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
}

int display_troop(t_mlx *win)
{
    static int counter = 0;
    static int current_frame = 0;

    if (win == NULL || win->arr == NULL)
        return (error_fct(1));

    display_troop_image(win, current_frame);

    if (counter % 400 == 0)
    {
        current_frame = (current_frame + 1) % 7;
        counter = 0;
    }
    counter++;

    return (0);
}

void	update_bullet_position(t_mlx *win, int i, int j, int *frame)
{
	win->arr[i][j] = '0';
	win->arr[i][j - 1] = 'B';
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bullet_img[1], (j - 1)
		* 64, i * 64);
	*frame = 0;
}
