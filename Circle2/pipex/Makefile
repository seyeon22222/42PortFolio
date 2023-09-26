# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seykim <seykim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 15:04:26 by seykim            #+#    #+#              #
#    Updated: 2023/07/11 17:00:23 by seykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c ft_split2.c pipex_utils.c pipex_utils2.c pipex_utils3.c ft_split_parse.c ft_split_utils.c
OBJS = $(SRCS:.c=.o)
BONUS_SRCS = pipex_bonus.c ft_split2_bonus.c pipex_utils_bonus.c pipex_utils2_bonus.c pipex_utils3_bonus.c ft_split_parse_bonus.c ft_split_utils_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
NAME = pipex
LIBFT = libft/libft.a

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	touch all
	make bonus -C libft
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

bonus : $(BONUS_OBJS)
	touch bonus
	make bonus -C libft
	$(CC) $(CFLAGS) $^ -o $(NAME) $(LIBFT)

clean:
	make clean -C libft
	rm -f $(OBJS) $(BONUS_OBJS) all bonus

fclean: clean
	make fclean -C libft
	rm -f $(NAME) $(BONUS)

re: fclean
	@make all

