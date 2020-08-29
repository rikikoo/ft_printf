# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 11:43:31 by rkyttala          #+#    #+#              #
#    Updated: 2020/08/29 05:53:25 by rkyttala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ARCC = ar

ARFLAGS = rc

SOURCES = $(wildcard *.c)

OBJECTS = $(SOURCES:.c=.o)

INCLUDES = libft.h get_next_line.h

MAKEFLAGS += --silent

all: $(NAME)

$(NAME): $(OBJECTS)
	$(ARCC) $(ARFLAGS) $(NAME) $(OBJECTS)

$(OBEJCTS):
	$(CC) $(CFLAGS) -c $(SOURCES) -I $(INCLUDES)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: $(NAME) all clean fclean re
