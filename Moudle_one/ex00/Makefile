CC =  c++ 
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone

SRCS = 	megaphone.cpp
all: $(NAME)

OBJS =  $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re