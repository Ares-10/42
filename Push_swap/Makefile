# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 19:27:01 by hyungcho          #+#    #+#              #
#    Updated: 2024/01/19 19:34:27 by johyeongeun      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = ps_algorithm_1.c ps_algorithm_2.c ps_func_1.c ps_func_2.c ps_utils_1.c ps_utils_2.c push_swap.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -c -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	cc -o $@ $^ libft.a

%.o: %.c
	cc $(CFLAGS) $< -o $@ -I push_swap.h -I libft.h -I ps_utils.h

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
