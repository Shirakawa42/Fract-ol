# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/26 20:45:05 by zadrien           #+#    #+#              #
#    Updated: 2017/01/31 14:31:09 by lvasseur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: make all clean fclean re

NAME = fractol

LIB = -L src/libft/ -lft

LIBFT = src/libft/libft.a

C_DIR = src/

SRCS = main.c mandelbrot.c julia.c burning_ship.c input.c palets.c

SRC = $(addprefix $(C_DIR), $(SRCS))

OBJ = $(SRCS:.c=.o)

INC = -I includes -I src/libft/

all : $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc -Wall -Wextra -Werror $^ -o $@ $(LIB) -lmlx -framework OpenGL -framework AppKit

$(LIBFT):
	make -C src/libft/

$(OBJ) : $(SRC)
	gcc -c -Wall -Wextra -Werror $^ $(INC)

clean :
	make clean -C src/libft/
	rm -f $(OBJ)

fclean : clean
	rm -f $(LIBFT)
	rm -f libft.a
	rm -f $(NAME)

re : fclean all
