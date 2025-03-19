/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:57:33 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/24 20:45:30 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	setup_game(t_mlx *win)
{
	setup_mlx(win);
	draw_background(win);
	put_collectable(win);
	display_door(win);
	put_troop(win);
	display_bullet(win);
	get_cooridnates_sprts(win->arr, win);
	setup_hooks(win);
	load_count(win);
	mlx_loop(win->mlx);
	return (0);
}

int	validate_and_setup(int argc, char **argv, t_mlx *win)
{
	int	check;
	int	valid;
	int	validate;

	if (validate_args(argc, argv, win))
		return (1);
	win->arr = fill_map_arr(argv[1]);
	validate = validate_map_features(win->arr, win);
	valid = check_map(win->arr);
	check = validate_map_size(win->arr);
	if (validate == 0 && valid == 1 && check == 0)
		setup_game(win);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	win;

	init_structs(&win);
	validate_and_setup(argc, argv, &win);
	free_all(win.arr);
	return (0);
}
