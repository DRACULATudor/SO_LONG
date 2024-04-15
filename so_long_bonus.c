/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:57:33 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/11 19:21:22 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	win;
	char	**arr;
	char	*relative_path;
	int valid, validate;

	init_struct(&win);
	init_struct2(&win);
	relative_path = "textures/Background.xpm";
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
	free_all(arr);
	return (0);
}
