/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:57:33 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/16 16:50:05 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	win;
	int valid, validate;

	init_struct(&win);
	init_struct2(&win);
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
		put_troop(&win);
		display_bullet(&win);
		get_cooridnates_sprts(win.arr, &win);
		setup_hooks(&win);
		load_count(&win);
		mlx_loop(win.mlx);
	}
	free_all(win.arr);
	return (0);
}
