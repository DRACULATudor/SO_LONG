/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:41:36 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/19 17:09:31 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "mlx_linux/mlx.h"
# include "printf/ft_printf.h"
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

typedef struct
{
	char	**map;
	int		x;
	int		y;
	int		map_width;
	int		map_height;
}			ValidCheckParams;

typedef struct s_bullet
{
	int		counter;
	int		frame;
	int		bullet_i;
	int		bullet_j;
	int		initial_i;
	int		initial_j;
}			t_bullet;

typedef struct s_mlx
{
	int		check_paa;
	int		dor_y;
	int		dor_x;
	int		width;
	int		height;
	int		special_key;
	int		x;
	int		bullet_x;
	int		bullet_y;
	int		leng;
	int		count1122;
	int		heng;
	int		last_row;
	int		last_col;
	bool	path;
	bool	number;
	bool	wall;
	bool	exit;
	bool	flag;
	bool	isd;
	bool	over;
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
	void	*over_img;
	void	*colectableimg;
	void	*background_img;
	void	*coin_imgs[8];
	void	*door_imgs[6];
	void	*bullet_img[7];
	char	**arr;
	char	**map2;
}			t_mlx;

typedef struct s_position
{
	int		i;
	int		j;
}			t_position;

typedef struct s_info
{
	int		info;
	int		position;
}			t_info;

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define MAX_WIDTH 61
# define MAX_HEIGHT 33

void		load_imagess(t_mlx *win);
void		init_images(t_mlx *win);
void		init_enemy_and_bullet(t_mlx *win);
void		init_door_and_coin(t_mlx *win);
void		init_struct(t_mlx *win);
void		init_struct2(t_mlx *win);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t len);
int			ft_strleng(char *str);
void		move_player(t_mlx *win, char **arr, t_position pos, int key_code);
int			close_event(t_mlx *win);
char		*ft_itoa(int n);
int			validate_map_features_custom(char **arr);
int			validate_map_features(char **arr, t_mlx *win);
int			error_fct(int num);
void		put_collectable(t_mlx *win);
void		display_door(t_mlx *win);
int			display_troop(t_mlx *win);
void		put_troop(t_mlx *win);
void		display_bullet(t_mlx *win);
int			ft_strleng(char *str);
int			ft_count_num(int n);
void		*ft_memset(void *b, int c, size_t len);
bool		check_for_colectables(t_mlx *win);
void		game_over(t_mlx *win);
int			get_p_x(char **map);
void		init_bullet(t_bullet *bullet);
int			get_p_y(char **map);
int			get_e_x(char **map);
void		kill_player(t_mlx *win, int keycode);
int			get_e_y(char **map);
int			get_b_y(char **map);
int			get_b_x(char **map);
void		length(t_mlx *win);
char		*ft_strcpy(char *dst, char *src);
void		free_arr(char **arr);
char		**error_fctc(int num);
char		**fill_map_arr(char *filename);
char		**allocate_new_arr(char **arr, int i);
void		draw_map(char **arr, t_mlx *win);
void		load_images(t_mlx *win, int img_width, int img_height);
void		get_cooridnates_sprts(char **arr, t_mlx *win);
int			bullet_shooting(t_mlx *win);
void		update_bullet_position(t_mlx *win, int i, int j, int *frame);
int			display_next_frame_and_door(t_mlx *win);
void		update_position(t_mlx *win, int key_code, char **arr);
void		load_count(t_mlx *win);
void		load_imagess(t_mlx *win);
int			key_hook(int key_code, t_mlx *win);
void		count_map_features(char **arr, int *pande, int *c, int *enemy);
int			check_valid(char **map, t_point size, t_point begin);
int			check_map(char **map);
int			validate_args(int argc, char **argv, t_mlx *win);
void		setup_mlx(t_mlx *win);
int			close_event(t_mlx *win);
void		draw_background(t_mlx *win);
int			display_all(t_mlx *win);
void		setup_hooks(t_mlx *win);
void		free_all(char **arr);
void		close_events(t_mlx *win);
void		count_map_featuress(char **arr, int *pande, int *c);
void		destroy_images(t_mlx *win);
int			key_press(int keycode, t_mlx *win);
void		init_structs(t_mlx *win);
int			validate_map_size(char **map);

#endif