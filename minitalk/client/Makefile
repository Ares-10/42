# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 02:57:16 by johyeongeun       #+#    #+#              #
#    Updated: 2024/02/28 22:35:23 by johyeongeun      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SRCS = 	minitalk.c 		\

OBJS = $(SRCS:.c=.o)

CFLAGS = -c -Wall -Wextra -Werror


all : $(NAME)

$(NAME) : $(OBJS)
	cc $^ lib/*.a -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ -I minitalk.h

clean :
	rm -rf $(OBJS)
	$(MAKE) -C lib fclean

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re