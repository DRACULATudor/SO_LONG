# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 16:47:59 by tlupu             #+#    #+#              #
#    Updated: 2024/04/02 12:19:51 by tlupu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
MLX_DIR = mlx_linux
MLX_LIB = libmlx.a
GET_NEXT_LINE = get_next_line.a
GNL_DIR = get_next_line
SRCS = so_long.c utils.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJS) $(MLX_DIR)/$(MLX_LIB) $(GNL_DIR)/$(GET_NEXT_LINE)
	$(CC) -o $(NAME) $(OBJS) -L$(MLX_DIR) -lmlx -L$(GNL_DIR) -l:$(GET_NEXT_LINE) -lXext -lX11 -lm

$(MLX_DIR)/$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(GNL_DIR)/$(GET_NEXT_LINE):
	$(MAKE) -C $(GNL_DIR)

clean:
	$(MAKE)	clean -C $(MLX_DIR)
	$(MAKE)	clean -C $(GNL_DIR)
	rm -f	$(OBJS)

fclean:	clean
	rm -f $(NAME)
	
re:	fclean all