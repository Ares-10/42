# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 02:57:16 by johyeongeun       #+#    #+#              #
#    Updated: 2024/02/28 22:40:39 by johyeongeun      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SUBDIRS =	lib			\
			client		\
			server		\

CFLAGS = -c -Wall -Wextra -Werror


all : $(NAME)

$(NAME) :
	for DIRS in $(SUBDIRS); do	\
		$(MAKE) -C $$DIRS;		\
	done
	cp client/client .			\
	cp server/server .			\

clean :
	for DIRS in $(SUBDIRS); do		\
		$(MAKE) -C $$DIRS fclean;	\
	done

fclean : clean
	rm -rf server client

re : fclean all

.PHONY : all clean fclean re