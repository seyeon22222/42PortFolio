# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seykim <seykim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 12:08:21 by seykim            #+#    #+#              #
#    Updated: 2023/06/06 14:21:49 by seykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS=ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
ft_striteri.c ft_strlcat.c ft_strlcpy.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
ft_strrchr.c ft_strtrim.c ft_tolower.c ft_toupper.c
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c
OBJS=$(SRCS:.c=.o)
BONUS_OBJS=$(BONUS_SRCS:.c=.o)
NAME=libft.a

.PHONY : bonus all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

bonus :
	@make 'OBJS=$(OBJS) $(BONUS_OBJS)' all

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
