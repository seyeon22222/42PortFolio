NAME = attack

## ANSI escape code
CYAN  := \033[1;36;40m
RESET := \033[0m
LOG   := printf "[$(CYAN)INFO$(RESET)] %s\n"

## file
HEADERS = Weapon.hpp HumanA.hpp HumanB.hpp
SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJS = $(SRCS:.cpp=.o)

## compile
CC=	c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: clean, fclean, re, all

all: $(NAME)

$(NAME): $(OBJS)
	@$(LOG) "Link"
	$(CC) -o $@ $(OBJS) 

$(OBJS): %.o: %.cpp $(HEADERS)
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
