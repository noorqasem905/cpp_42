CC =  c++ 
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = zombie

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS = $(SRCS:.cpp=.o)
all: $(NAME)

OBJS =  $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re