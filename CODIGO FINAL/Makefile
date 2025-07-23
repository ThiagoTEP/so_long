# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thevaris <thevaris@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 14:25:08 by thevaris          #+#    #+#              #
#    Updated: 2025/07/22 14:47:55 by thevaris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SCR = main.c check_map.c render.c exit_game.c init.c handle_key.c start_game.c check_path.c errors.c

OBJ = $(SCR:.c=.o)

CFLAGS += -Wall -Werror -Wextra

LIBFT = ./libft/libft.a
MLX_LIB = ./minilibx-linux

FLAGS += -lmlx -lXext -lX11 -Lminilibx-linux

all: $(NAME)

$(NAME):$(MLX_LIB) $(OBJ)
	@make -C libft > /dev/null 2>&1
	@make -C minilibx-linux > /dev/null 2>&1
	@cc $(OBJ)  $(CFLAGS) $(LIBFT) $(FLAGS) -o $(NAME)
	@echo "\n------------- COMPILATION DONE -------------\n"

clean:
	@rm -f $(OBJ)
	@make -C libft clean  > /dev/null 2>&1
	@make -C minilibx-linux clean > /dev/null 2>&1
	@echo "\n------------- REMOVED OBJECTS -------------\n"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean  > /dev/null 2>&1
	@echo "\n------------- REMOVED	 EXECUTABLES -------------\n"

$(MLX_LIB):
	@wget https://cdn.intra.42.fr/document/document/36126/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz
	@rm minilibx-linux.tgz
	@echo "\n------------- DOWNLOADED -------------\n"

re: clean all

.PHONY: all clean fclean re