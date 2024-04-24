/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:57:33 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/24 19:32:25 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	win;
	int		valid;
	int		validate;
	int		check;

	init_structs(&win);
	if (validate_args(argc, argv, &win))
		return (1);
	win.arr = fill_map_arr(argv[1]);
	valid = check_map(win.arr);
	validate = validate_map_features(win.arr, &win);
	check = validate_map_size(win.arr);
	if (validate == 0 && valid == 1 && check == 0)
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
