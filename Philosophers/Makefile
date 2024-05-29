NAME = philo

SRCS =  main.c		\
		error.c		\
		utils.c		\
		thread.c	\

OBJS = $(SRCS:.c=.o)

# CFLAGS = -Wall -Wextra -Werror


all : $(NAME)

$(NAME) : $(OBJS)
	cc $^ -lpthread -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ -I philo.h

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re