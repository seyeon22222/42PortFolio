NAME = philo

## ANSI escape code
CYAN  := \033[1;36;40m
RESET := \033[0m
LOG   := printf "[$(CYAN)INFO$(RESET)] %s\n"

## directory
INC_DIRS += include
SRC_DIRS = src

## search all file
vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

## file
HEADERS = philosophers.h
SRCS = ft_atoi.c main.c init.c util.c thr.c
OBJS = $(SRCS:.c=.o)

## compile
CC=	cc #-fsanitize=thread
CFLAGS = -Wall -Wextra -Werror  $(addprefix -I,$(INC_DIRS))

.PHONY: clean, fclean, re, all

all: $(NAME)

$(NAME): $(OBJS)
	@$(LOG) "Link"
	$(CC) -o $@ $(OBJS) 

$(OBJS): %.o: %.c $(HEADERS)
	@$(LOG) "Compile"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(LOG) "clean"
	@rm -f $(OBJS) 

fclean: clean
	@$(LOG) "fclean"
	@rm -f $(NAME)

re:
	@$(LOG) "re"
	@make fclean
	@make all
