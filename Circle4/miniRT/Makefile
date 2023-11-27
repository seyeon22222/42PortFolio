# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seykim <seykim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 14:11:28 by seykim            #+#    #+#              #
#    Updated: 2023/11/27 20:31:32 by seykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## ANSI escape code
CYAN  := \033[1;36;40m
RESET := \033[0m
LOG   := printf "[$(CYAN)INFO$(RESET)] %s\n"

## directory
INC_DIRS += include
SRC_DIRS = src src/initailize src/util src/mlx_func src/vector

vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

CC=cc 
#-g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror $(addprefix -I,$(INC_DIRS))
CLIB= -lmlx -framework OpenGl -framework AppKit -Imlx
HEADERS = minirt.h get_next_line.h
SRCS= main.c get_next_line_utils.c get_next_line.c file_init.c info_init1.c info_init2.c\
error_check.c ft_atof.c alight_check.c camera_check.c light_check.c sphere_check.c plane_check.c\
cylinder_check.c mlx_func.c mlx_func2.c mlx_func3.c vector_func.c vector_func2.c\
vector_func3.c
OBJS=$(SRCS:.c=.o)
#BONUS_OBJS=$(BONUS_SRCS:.c=.o)
NAME=miniRT
LIBFT= libft/libft.a
PRINTF = printf/libftprintf.a

.PHONY : bonus all clean fclean re

all : $(NAME)

$(NAME):$(OBJS)
	@$(LOG) "Linking"
	@make -C libft
	@make -C printf
	@make -C mlx
	$(CC) $(CFLAGS) $(CLIB) $^ -o $@ ./$(LIBFT) ./$(PRINTF) ./mlx/libmlx.a

$(OBJS): %.o: %.c $(HEADERS)
	@$(LOG) "Compiling.."
	@$(CC) $(CFLAGS) -o $@ -c $<

# bonus : $(BONUS)

# $(BONUS):$(BONUS_OBJS)
# 	$(CC) $(CFLAGS) $(CLIB) $^ -o $@ ./$(LIBFT) ./$(PRINTF) ./mlx/libmlx.a

clean:
	@$(LOG) "clean"
	@make clean -C libft
	@make clean -C mlx
	@make clean -C printf
	@rm -f $(OBJS) 
#$(BONUS_OBJS)

fclean: clean
	@$(LOG) "fclean"
	@make fclean -C libft
	@make fclean -C printf
	@make clean -C mlx
	@rm -f $(NAME)
#$(BONUS)

re:
	@$(LOG) "re"
	@make fclean
	@make all
