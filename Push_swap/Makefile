# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 19:27:01 by hyungcho          #+#    #+#              #
#    Updated: 2024/02/05 19:50:36 by johyeongeun      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = ps_algorithm_1.c ps_algorithm_2.c ps_func_1.c ps_func_2.c ps_utils_1.c ps_utils_2.c push_swap.c ps_check_best.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -c -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) -C ./Libft all
	mv Libft/libft.a libft.a
	cc -o $@ $^ libft.a

%.o: %.c
	cc $(CFLAGS) $< -o $@ -I push_swap.h -I libft.h -I ps_utils.h

clean :
	@$(MAKE) -C ./Libft clean
	@rm -rf $(OBJS)
	rm -rf libft.a

fclean : clean
	@$(MAKE) -C ./Libft fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
