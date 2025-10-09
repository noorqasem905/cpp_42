CXX =  c++ 
CFLAGS = -Wall -Wextra -Werror -std=c++98
ARFLAGS = rcs
NAME = zombie

SRCS = main.cpp Zombie.cpp zombieHorde.cpp
all: $(NAME)

OBJS =  $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re