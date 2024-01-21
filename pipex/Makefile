# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 02:57:16 by johyeongeun       #+#    #+#              #
#    Updated: 2024/01/20 02:58:07 by johyeongeun      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = 

OBJS = $(SRCS:.c=.o)

CFLAGS = -c -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	cc -o $@ $^ libft.a

%.o: %.c
	cc $(CFLAGS) $< -o $@ -I 

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re