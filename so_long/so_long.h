/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:41:36 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/05 20:21:45 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "mlx_linux/mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_mlx
{
	int		width;
	int		height;
	int		special_key;
	int		x;
	int		bullet_x;
	int		bullet_y;
	bool	path;
	bool	exit;
	bool	flag;
	bool	isd;
	bool 	over;
	bool	is_bullet_active;
	int		y;
	int		key_release;
	void	*mlx;
	void	*enemy[8];
	void	*bullet;
	void	*mlx_win;
	void	*test_img;
	void	*charcaterimg;
	void	*character_img_l;
	void	*character_img_r;
	void	*character_img_ur;
	void	*character_img_Ul;
	void 	*over_img;
	void	*colectableimg;
	void	*background_img;
	void	*coin_imgs[8];
	void	*door_imgs[6];
	void	*bullet_img[7];
	char	**arr;
}			t_mlx;

typedef struct s_info
{
	int		info;
	int		position;
}			t_info;

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 27
# define TS 64
# define MAX 100

void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t len);
int			ft_strleng(char *str);
int			close_event(t_mlx *win);

#endif