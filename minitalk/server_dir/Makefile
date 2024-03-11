# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 02:57:16 by johyeongeun       #+#    #+#              #
#    Updated: 2024/03/07 14:03:00 by johyeongeun      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

SRCS = 	server.c 		\

OBJS = $(SRCS:.c=.o)

CFLAGS = -c -Wall -Wextra -Werror


all : $(NAME)

$(NAME) : $(OBJS)
	cc $^ ../lib/*.a -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ -I server.h

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re