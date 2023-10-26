# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seykim <seykim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 14:11:28 by seykim            #+#    #+#              #
#    Updated: 2023/10/11 16:36:11 by seykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## ANSI escape code
CYAN  := \033[1;36;40m
RESET := \033[0m
LOG   := printf "[$(CYAN)INFO$(RESET)] %s\n"

## directory
INC_DIRS += include
SRC_DIRS = src

vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

CC=cc
CFLAGS = -Wall -Wextra -Werror $(addprefix -I,$(INC_DIRS))
CLIB= -lmlx -framework OpenGl -framework AppKit -Imlx
HEADERS = minirt.h get_next_line.h
SRCS=
OBJS=$(SRCS:.c=.o)
#BONUS_OBJS=$(BONUS_SRCS:.c=.o)
NAME=miniRT
LIBFT=libft/libft.a

.PHONY : bonus all clean fclean re

all : $(NAME)

$(NAME):$(OBJS)
	@$(LOG) "Linking"
	@make -C libft
	@make -C mlx
	$(CC) $(CFLAGS) $(CLIB) $^ -o $@ ./$(LIBFT) ./mlx/libmlx.a

$(OBJS): %.o: %.c $(HEADERS)
	@$(LOG) "Compiling.."
	@$(CC) $(CFLAGS) -o $@ -c $<

# bonus : $(BONUS)

# $(BONUS):$(BONUS_OBJS)
# 	$(CC) $(CFLAGS) $(CLIB) $^ -o $@ ./$(LIBFT) ./mlx/libmlx.a

clean:
	@$(LOG) "clean"
	@make clean -C libft
	@make clean -C mlx
	@rm -f $(OBJS) 
#$(BONUS_OBJS)

fclean: clean
	@$(LOG) "fclean"
	@make fclean -C libft
	@make fclean -C mlx
	@rm -f $(NAME)
#$(BONUS)

re:
	@$(LOG) "re"
	@make fclean
	@make all
