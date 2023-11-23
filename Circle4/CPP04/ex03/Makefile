NAME = Materia

## ANSI escape code
CYAN  := \033[1;36;40m
RESET := \033[0m
LOG   := printf "[$(CYAN)INFO$(RESET)] %s\n"

## file
HEADERS = AMateria.hpp Character.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp Cure.hpp
SRCS = AMateria.cpp Character.cpp Ice.cpp MateriaSource.cpp main.cpp Cure.cpp
OBJS = $(SRCS:.cpp=.o)

## compile
CXX=	c++ 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 
#-Wall -Wextra -Werror
#-g3 -fsanitize=address
.PHONY: clean, fclean, re, all

all: $(NAME)

$(NAME): $(OBJS)
	@$(LOG) "Link"
	$(CXX) -o $@ $(OBJS) 

$(OBJS): %.o: %.cpp $(HEADERS)
	@$(LOG) "Compile"
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

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
