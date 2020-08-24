# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/12 13:37:40 by rkyttala          #+#    #+#              #
#    Updated: 2020/08/24 18:59:57 by rkyttala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB = libft.a

SRC_NAME = ft_printf.c parsers.c validate.c csp.c diu.c octal.c hexadecimal.c \
			float.c oux_conversion.c

OBJ = $(SRC_NAME:%.c=%.o)

DIR_LIB = libft/

DIR_SRC = src/

DIR_OBJ = obj/

HEADER = inc/ft_printf.h

FLAGS = -Wall -Wextra -Werror

MAKEFLAGS += --silent

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	cp $(addprefix $(DIR_LIB), $(LIB)) .
	mv $(LIB) $(NAME)
	ar rc $(NAME) $(addprefix $(DIR_OBJ), $(OBJ))
	ranlib $(NAME)

$(OBJ):
	gcc $(FLAGS) -c $(SRC_NAME:%.c=$(DIR_SRC)%.c) -I $(HEADER)
	mv $(OBJ) $(DIR_OBJ)

re: fclean all

clean:
	rm -rf main.o $(addprefix $(DIR_OBJ), $(OBJ))
	make clean -C libft/

fclean: clean
	rm -rf $(NAME) a.out a.out.dSYM
	make fclean -C libft/

test:
	gcc $(FLAGS) -o ft_printf main.c $(addprefix $(DIR_SRC), $(SRC)) $(NAME)

debug:
	gcc -g $(SRC_NAME:%.c=$(DIR_SRC)%.c) main.c $(NAME) -I $(HEADER)

.PHONY = all re clean fclean