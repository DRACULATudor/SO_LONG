/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:41:36 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/01 21:54:34 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "lib/mlx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>
# include <unistd.h>

typedef struct s_mlx
{
	int		width;
	int		height;
	int 	special_key;
	int 	x;
	int 	y;
	void	*mlx;
	void	*mlx_win;
	void	*test_img;
	void	*charcaterimg;
	void 	*character_img_l;
	void 	*character_img_r;
	void	*character_img_ur;
	void 	*character_img_Ul;
	void	*colectableimg;
	void 	*background_img;
	void	*coin_imgs[8];
	void	*door_imgs[6];
	char	**arr;
}			t_mlx;

typedef	struct s_info
{
	int info;
	int position;
}		t_info;

# define W 119
# define A 97
# define S 115
# define D 100
# define TS 64

void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t len);
int			ft_strleng(char *str);

#endif