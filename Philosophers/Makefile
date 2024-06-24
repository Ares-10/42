NAME = philo

SRCS =  main.c		\
		error.c		\
		utils.c		\
		thread.c	\
		philoset.c	\

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror	\
		# -g3 -fsanitize=thread	\
		# -fsanitize=address		\


all : $(NAME)

$(NAME) : $(OBJS)
	cc $(CFLAGS) $^ -lpthread -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ -I philo.h

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re