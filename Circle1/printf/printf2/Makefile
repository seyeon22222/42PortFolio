# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seykim <seykim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 12:08:21 by seykim            #+#    #+#              #
#    Updated: 2023/03/31 14:03:48 by seykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS=  $(wildcard *.c)
OBJS=$(SRCS:.c=.o)
NAME= libftprintf.a

.PHONY : bonus all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
