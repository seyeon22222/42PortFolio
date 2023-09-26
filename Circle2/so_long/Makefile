# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seykim <seykim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 14:11:28 by seykim            #+#    #+#              #
#    Updated: 2023/06/20 21:05:49 by seykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror -fsanitize=address
CLIB=-lmlx -framework OpenGl -framework AppKit -Imlx
SRCS=get_next_line.c get_next_line_utils.c mlx_move.c mlx_make.c so_long_utils.c so_long_utils2.c so_long.c
BONUS_SRCS = get_next_line.c get_next_line_utils.c mlx_move_bonus.c \
mlx_make_bonus.c so_long_utils_bonus.c so_long_utils2_bonus.c so_long_bonus.c
OBJS=$(SRCS:.c=.o)
BONUS_OBJS=$(BONUS_SRCS:.c=.o)
NAME=so_long
BONUS=so_long_bonus
LIBFT=libft/libft.a

.PHONY : bonus all clean fclean re

all : $(NAME)

$(NAME):$(OBJS)
	make bonus -C libft
	make -C mlx
	$(CC) $(CFLAGS) $(CLIB) $^ -o $@ ./$(LIBFT) ./mlx/libmlx.a

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

bonus : $(BONUS)

$(BONUS):$(BONUS_OBJS)
	$(CC) $(CFLAGS) $(CLIB) $^ -o $@ ./$(LIBFT) ./mlx/libmlx.a

clean:
	make clean -C libft
	rm -f $(OBJS) $(BONUS_OBJS)

fclean:clean
	make fclean -C libft
	make clean -C mlx
	rm -f $(NAME) $(BONUS)

re:fclean all
