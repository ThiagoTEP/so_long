# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thevaris <thevaris@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/27 11:04:04 by thevaris          #+#    #+#              #
#    Updated: 2025/04/27 11:04:06 by thevaris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** 

NAME = libft.a
CC = cc
FLAG = -Wall -Werror -Wextra
SRC = ft_printf.c ft_putchar.c ft_putnbr_hex.c ft_putnbr.c \
      ft_putstr.c ft_putpointer.c ft_putnbr_un.c \
      get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

AR = ar rcs
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(FLAG) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
