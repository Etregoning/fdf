# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etregoni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/21 14:58:27 by etregoni          #+#    #+#              #
#    Updated: 2017/06/25 19:32:38 by etregoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
CFLAGS	= -Wall -Werror -Wextra -lmlx -lft -framework OpenGL -framework AppKit
INCLUDES = -I./includes/mlx -I./includes/libft -L./includes/mlx -L./includes/libft
SRC 		= main.c parse.c store.c environment.c slope.c draw.c
OBJ			= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(CFLAGS) $(SRC) $(INCLUDES) -o $(NAME)

debug:
	@gcc $(CFLAGS) -g $(SRC) $(INCLUDES) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
