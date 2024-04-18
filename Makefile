# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 16:47:59 by tlupu             #+#    #+#              #
#    Updated: 2024/04/17 19:41:21 by tlupu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc -g
MLX_DIR = mlx_linux
MLX_LIB = libmlx.a
GET_NEXT_LINE = get_next_line.a
GNL_DIR = get_next_line
SRCS = so_long.c mandatory/game/game_disp_sprites.c mandatory/game/game_move_charact.c mandatory/game/rendering.c mandatory/helper/utils.c \
		mandatory/helper/utils2.c mandatory/helper/utils3.c mandatory/load_textures/textures.c mandatory/map_arr/map_make.c \
		mandatory/map_checks/map_checks.c mandatory/map_checks/path_checks.c mandatory/helper/utils4.c \

OBJS = $(SRCS:.c=.o)
OBJSBON = $(BONUS:.c=.o)
BONUS = so_long_bonus.c bonus/helper/utils.c bonus/map_validate/map_features.c bonus/errors/errors.c bonus/load_textures/textures.c \
		bonus/helper/utils1.c bonus/helper/utils2.c bonus/map_fill_cordinates/map_coordinates.c bonus/game_features/features.c bonus/game_features/shooting.c\
		bonus/game_features/door.c bonus/game_features/movement.c bonus/game_features/movement2.c bonus/helper/utils3.c\
		bonus/map_fill_cordinates/more_checks.c bonus/game_features/rendering.c\
		
%.o: %.c
	$(CC) -Wall -Wextra -Werror -g -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(MLX_DIR)/$(MLX_LIB) $(GNL_DIR)/$(GET_NEXT_LINE)
	$(CC) -o $(NAME) $(OBJS) -L$(MLX_DIR) -lmlx -L$(GNL_DIR) -l:$(GET_NEXT_LINE) -lXext -lX11 -lm

bonus: $(OBJSBON) $(MLX_DIR)/$(MLX_LIB) $(GNL_DIR)/$(GET_NEXT_LINE)
	$(CC) -o $(NAME) $(OBJSBON) -L$(MLX_DIR) -lmlx -L$(GNL_DIR) -l:$(GET_NEXT_LINE) -lXext -lX11 -lm

$(MLX_DIR)/$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(GNL_DIR)/$(GET_NEXT_LINE):
	$(MAKE) -C $(GNL_DIR)

clean:
	$(MAKE)	clean -C $(MLX_DIR)
	$(MAKE)	clean -C $(GNL_DIR)
	rm -f	$(OBJS) 
	rm -f 	$(OBJSBON)

fclean:	clean
	rm -f $(NAME)
	
re:	fclean all