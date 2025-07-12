
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx -Iminilibx-linux -Ilibft

# Diretórios
LIBFT_DIR = libft
MLX_DIR = minilibx-linux

# Bibliotecas
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

SRC = main.c map.c render.c player.c init.c utils.c
OBJ = $(SRC:.c=.o)
RM = rm -rf

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) -lXext -lX11 -lm

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
