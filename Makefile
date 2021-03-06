# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkyttala <rkyttala@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/12 13:37:40 by rkyttala          #+#    #+#              #
#    Updated: 2020/09/02 16:47:05 by rkyttala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB = libft.a

SRC_NAME = ft_printf.c parsers.c validate.c csp.c di.c octal.c hexadecimal.c \
			unsigned.c float.c utils.c

OBJ = $(SRC_NAME:%.c=%.o)

DIR_LIB = libft/

DIR_SRC = src/

HEADER = inc/ft_printf.h

FLAGS = -Wall -Wextra -Werror

MAKEFLAGS += --silent

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	cp $(addprefix $(DIR_LIB), $(LIB)) .
	mv $(LIB) $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ):
	gcc $(FLAGS) -c $(SRC_NAME:%.c=$(DIR_SRC)%.c) -I $(HEADER)

re: fclean all

clean:
	rm -rf main.o $(OBJ)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME) ft_printf a.out a.out.dSYM
	make fclean -C libft/

test:
	gcc -o ft_printf main.c $(NAME)

debug:
	gcc -g $(SRC_NAME:%.c=$(DIR_SRC)%.c) main.c $(NAME) -I $(HEADER)

.PHONY = all re clean fclean
