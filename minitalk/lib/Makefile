# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 02:57:16 by johyeongeun       #+#    #+#              #
#    Updated: 2024/02/28 22:28:15 by johyeongeun      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib

SUBDIRS = 	src/Libft		\
			src/ft_printf	\

CFLAGS = -c -Wall -Wextra -Werror


all : $(NAME)

$(NAME) :
	for DIRS in $(SUBDIRS); do	\
		$(MAKE) -C $$DIRS;		\
		mv $$DIRS/*.a . ;	\
	done

clean :
	for DIRS in $(SUBDIRS); do		\
		$(MAKE) -C $$DIRS fclean;	\
	done

fclean : clean
	rm -rf *.a

re : fclean all

.PHONY : all clean fclean re