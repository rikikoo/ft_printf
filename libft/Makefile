#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 11:43:31 by rkyttala          #+#    #+#              #
#    Updated: 2019/12/13 19:38:56 by rkyttala         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ARCC = ar

ARFLAGS = rc

SOURCES = $(wildcard *.c)

OBJECTS = $(SOURCES:.c=.o)

INCLUDES = libft.h get_next_line.h

all: $(NAME)

$(NAME): $(OBJECTS)
	$(ARCC) $(ARFLAGS) $(NAME) $(OBJECTS)

$(OBEJCTS):
	$(CC) $(CFLAGS) -c $(SOURCES) -I $(INCLUDES)

clean:
	rm -fv $(OBJECTS)

fclean: clean
	rm -fv $(NAME)

re: fclean all

.PHONY: $(NAME)