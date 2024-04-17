/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:57:33 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/17 16:15:23 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void init_structs(t_mlx *win)
{
	init_struct(win);
	init_struct2(win);
}

int main(int argc, char **argv)
{
    t_mlx win;
    char *relative_path = "textures/Background.xpm";
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
	free_all(win.arr);
    return (0);
}
