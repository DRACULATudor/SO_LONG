/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:41:36 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/26 17:13:08 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 

#include <stdio.h>
#include <unistd.h>
#include "lib/mlx_linux/mlx.h"
#include "get_next_line/get_next_line.h"
#include <stdlib.h>

typedef struct s_mlx
{
	int		width;
	int		height;
	void	*mlx;
	void	*mlx_win;
	void	*test_img;
}				t_mlx;

void	*ft_memmove(void *dst, const void *src, size_t len);
void   *ft_memcpy(void *dst, const void *src, size_t len);
int ft_strleng(char *str);

#endif