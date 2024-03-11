# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 02:57:16 by johyeongeun       #+#    #+#              #
#    Updated: 2024/03/07 14:07:37 by johyeongeun      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SUBDIRS =	lib			\
			client_dir	\
			server_dir	\

CFLAGS = -c -Wall -Wextra -Werror


all : $(NAME)

$(NAME) :
	for DIRS in $(SUBDIRS); do	\
		$(MAKE) -C $$DIRS;		\
	done
	cp client_dir/client .
	cp server_dir/server .

clean :
	for DIRS in $(SUBDIRS); do		\
		$(MAKE) -C $$DIRS fclean;	\
	done

fclean : clean
	rm server client

re : fclean all

.PHONY : all clean fclean re