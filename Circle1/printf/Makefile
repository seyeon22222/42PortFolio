# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seykim <seykim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 12:08:21 by seykim            #+#    #+#              #
#    Updated: 2023/04/06 17:06:37 by seykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS=  ft_format_csp.c ft_format_diu.c ft_format_xx1.c ft_func.c ft_func2.c ft_printf.c error.c error_func.c error_format.c
OBJS=$(SRCS:.c=.o)
NAME= libftprintf.a

.PHONY : all clean fclean re

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
