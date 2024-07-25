NAME = megaphone

SRCS =  megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98	\


all : $(NAME)

$(NAME) : $(OBJS)
	g++ $(CPPFLAGS) $^ -o $(NAME)

%.o: %.c
	g++ $(CPPFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re