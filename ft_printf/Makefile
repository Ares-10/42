# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 19:27:01 by hyungcho          #+#    #+#              #
#    Updated: 2023/11/12 20:07:40 by hyungcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# SRCS

# SRCS_BONUS

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CFLAGS = -c -Wall -Wextra -Werror


all : $(NAME)

$(NAME) : $(OBJS)
	ar -r $@ $^

%.o: %.c
	cc $(CFLAGS) $< -o $@ -I libft.h

clean :
	rm -rf $(OBJS) $(OBJS_BONUS) _BONUS

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus :	_BONUS

_BONUS : $(OBJS) $(OBJS_BONUS)
	touch _BONUS
	ar -r $(NAME) $^

.PHONY : all clean fclean re bonus