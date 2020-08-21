# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/12 13:37:40 by rkyttala          #+#    #+#              #
#    Updated: 2020/08/19 17:01:30 by rkyttala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRC_NAME = ft_printf.c parsers.c validate.c csp.c diu.c octal.c hexadecimal.c \
			float.c

OBJ = $(SRC_NAME:%.c=%.o) main.o

DIR_SRC = src/

LIB = ../libft/libft.a

HEADER = inc/ft_printf.h

FLAGS = -Wall -Wextra -Werror

MAKEFLAGS += --silent

all: $(NAME)

$(NAME): $(OBJ)
	make -C ../libft/
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) -I $(HEADER)

$(OBJ):
	gcc $(FLAGS) -c $(SRC_NAME:%.c=$(DIR_SRC)%.c) main.c -I $(HEADER)

re: fclean all

clean:
	rm -rf $(OBJ)
	make clean -C ../libft/

fclean: clean
	rm -rf $(NAME) a.out a.out.dSYM
	make fclean -C ../libft/

test:
	gcc -c main.c -I $(HEADER)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) -I $(HEADER)

debug:
	gcc -g $(SRC_NAME:%.c=$(DIR_SRC)%.c) main.c $(LIB) -I $(HEADER)

.PHONY = all re clean fclean
