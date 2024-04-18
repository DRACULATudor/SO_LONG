/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:57:33 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/17 19:41:41 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_fct(int num)
{
	num = 1;
	write(2, "Error\n", 7);
	return (num);
}

void	load_images(t_mlx *win, int img_width, int img_height)
{
	char	*relative_path_wall;
	char	*relative_path_character;

	relative_path_wall = "textures/wall.xpm";
	relative_path_character = "textures/character/CharacterRight.xpm";
	win->test_img = mlx_xpm_file_to_image(win->mlx, relative_path_wall,
			&img_width, &img_height);
	win->charcaterimg = mlx_xpm_file_to_image(win->mlx, relative_path_character,
			&img_width, &img_height);
}

void init_structs(t_mlx *win)
{
	init_struct(win);
	init_struct2(win);
}

int main(int argc, char **argv)
{
    t_mlx win;
    int valid, validate;

	init_structs(&win);
    if (validate_args(argc, argv, &win))
        return (1);
    win.arr = fill_map_arr(argv[1]);
    valid = check_map(win.arr);
    validate = validate_map_features(win.arr, &win);
    if (validate == 0 && valid == 1)
    {
        setup_mlx(&win);
        draw_background(&win);
        put_collectable(&win);
        display_door(&win);
        get_cooridnates_sprts(win.arr, &win);
        setup_hooks(&win);
        mlx_loop(win.mlx);
    }
	free_arr(win.arr);
    return (0);
}
