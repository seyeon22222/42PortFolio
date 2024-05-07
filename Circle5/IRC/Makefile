CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRC = main.cpp KQueue.cpp Socket.cpp IRCServer.cpp Util.cpp IRC.cpp
SRC += Regex/Lexer.cpp Regex/Table.cpp Regex/Token.cpp Regex/DFA.cpp Regex/Regex.cpp Regex/AST.cpp
OBJ = $(SRC:.cpp=.o)
NAME = ircserv

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all