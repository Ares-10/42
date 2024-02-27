# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 19:27:01 by hyungcho          #+#    #+#              #
#    Updated: 2024/02/26 19:45:55 by johyeongeun      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = 	so_long.c 							\
		sl_mapcheck.c						\
		sl_queue.c							\
		sl_graphic.c						\
		sl_graphic_utils.c					\
		get_next_line/get_next_line.c 		\
		get_next_line/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

SUBDIRS = 	Libft						\
			minilibx_opengl_20191021	\

CFLAGS = -c -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	for DIRS in $(SUBDIRS); do	\
		$(MAKE) -C $$DIRS;		\
	done
	mv Libft/libft.a libft.a
	mv minilibx_opengl_20191021/libmlx.a libmlx.a
	cc -L. -lmlx -framework OpenGL -framework AppKit $^ libft.a -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -Imlx -c $< -o $@ -I so_long.h -I sl_graphic.h

clean :
	rm -rf $(OBJS)
	rm -rf libft.a libmlx.a
	for DIRS in $(SUBDIRS); do		\
		$(MAKE) -C $$DIRS clean;	\
	done

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
