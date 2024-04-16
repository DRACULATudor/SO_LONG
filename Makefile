# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 16:47:59 by tlupu             #+#    #+#              #
#    Updated: 2024/04/15 14:19:27 by tlupu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc -g
MLX_DIR = mlx_linux
MLX_LIB = libmlx.a
GET_NEXT_LINE = get_next_line.a
GNL_DIR = get_next_line
SRCS = so_long.c helper/utils.c 
OBJS = $(SRCS:.c=.o)
OBJSBON = $(BONUS:.c=.o)
BONUS = so_long_bonus.c helper/utils.c map_validate/map_features.c errors/errors.c load_textures/textures.c \
		helper/utils1.c helper/utils2.c map_fill_cordinates/map_coordinates.c game_features/features.c game_features/shooting.c\
		game_features/door.c game_features/movement.c game_features/movement2.c helper/utils3.c\
		map_fill_cordinates/more_checks.c game_features/rendering.c \
		
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