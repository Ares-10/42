# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 19:27:01 by hyungcho          #+#    #+#              #
#    Updated: 2024/02/28 20:28:31 by johyeongeun      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -c -Wall -Wextra -Werror


all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $@ $^

%.o: %.c
	cc $(CFLAGS) $< -o $@ -I ft_printf.h -I ft_printf_utils.h

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re