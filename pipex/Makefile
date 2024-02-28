# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 02:57:16 by johyeongeun       #+#    #+#              #
#    Updated: 2024/02/28 19:24:48 by johyeongeun      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = 	pipex.c 							\

OBJS = $(SRCS:.c=.o)

SUBDIRS = 	Libft		\
			ft_printf	\

CFLAGS = -c -Wall -Wextra -Werror


all : $(NAME)

$(NAME) : $(OBJS)
	for DIRS in $(SUBDIRS); do	\
		$(MAKE) -C $$DIRS;		\
	done
	mv Libft/libft.a libft.a
	mv ft_printf/libftprintf.a libftprintf.a
	cc $^ libft.a libftprintf.a -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -Imlx -c $< -o $@ -I pipex.h

clean :
	rm -rf $(OBJS)
	for DIRS in $(SUBDIRS); do		\
		$(MAKE) -C $$DIRS fclean;	\
	done

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re