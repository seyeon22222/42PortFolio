# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seykim <seykim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 15:44:17 by seykim            #+#    #+#              #
#    Updated: 2023/05/23 14:51:29 by seykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS = push_swap.c push_swap_fun.c push_swap_fun2.c push_swap_fun3.c push_swap_fun4.c \
push_swap_sort_345.c push_swap_sort_else.c push_swap_utils.c push_swap_utils2.c
BONUS_SRCS = push_swap_bonus.c push_swap_bonus_sort_345.c \
push_swap_bonus_sort_else.c push_swap_bonus_utils.c push_swap_bonus_utils2.c \
push_swap_bonus_func.c push_swap_bonus_func2.c push_swap_bonus_func3.c push_swap_bonus_func4.c\
push_swap_bonus_func5.c push_swap_bonus_func6.c
OBJS=$(SRCS:.c=.o)
BONUS_OBJS=$(BONUS_SRCS:.c=.o)
BONUS=checker
NAME=push_swap
LIBFT=libft/libft.a

.PHONY : bonus all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	make bonus -C libft
	$(CC) $(CFLAGS) $^ -o $@ ./$(LIBFT)

bonus : $(BONUS)

$(BONUS) : $(BONUS_OBJS)
	$(CC) $(CFLAGS) $^ -o $@ ./$(LIBFT)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	make clean -C libft
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	make fclean -C libft
	rm -f $(NAME) $(BONUS)

re : fclean all
