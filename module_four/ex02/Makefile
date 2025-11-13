CC =  c++ 
CFLAGS = -Wall -Wextra -Werror -std=c++98
ARFLAGS = rcs
NAME = Animal
all: $(NAME)
SRCS = main.cpp Dog.cpp Cat.cpp Animal.cpp Brain.cpp WrongAnimal.cpp WrongCat.cpp

OBJS =  $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re