NAME = ZombieHorde

SRCS =	main.cpp		\
		Zombie.cpp		\
		ZombieHorde.cpp	\

OBJS = $(SRCS:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98	\


all : $(NAME)

$(NAME) : $(OBJS)
	c++ $(CPPFLAGS) $^ -o $(NAME)

%.o: %.cpp
	c++ $(CPPFLAGS) -c $< -o $@ -I.

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re