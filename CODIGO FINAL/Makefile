NAME = so_long

SCR = so_long.c check_map.c read_map.c exit_game.c gather_elements.c handle_key.c start_game.c check_path.c errors.c

OBJ = $(SCR:.c=.o)

CFLAGS += -Wall -Werror -Wextra

LIBFT = ./libft/libft.a
MLX_LIB = ./minilibx-linux

FLAGS += -lmlx -lXext -lX11 -Lminilibx-linux

all: $(NAME)

$(NAME):$(MLX_LIB) $(OBJ)
	@cd libft && make
	@cd minilibx-linux && make
	@cc $(OBJ)  $(CFLAGS) $(LIBFT) $(FLAGS) -o $(NAME)
	@echo "\n------------- COMPILATION DONE -------------\n"

clean:
	@rm -f $(OBJ)
	@make -C libft clean
	@make -C minilibx-linux clean
	@echo "\n------------- REMOVED OBJECTS -------------\n"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@echo "\n------------- REMOVED	 EXECUTABLES -------------\n"

$(MLX_LIB):
	@wget https://cdn.intra.42.fr/document/document/36126/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz
	@rm minilibx-linux.tgz
	@echo "\n------------- DOWNLOADED -------------\n"

re: clean all

.PHONY: all clean fclean re