NAME = libft.a

SRC_PART_1	=		ft_isalpha.c	\
					ft_isdigit.c	\
					ft_isalnum.c	\
					ft_isascii.c	\
					ft_isprint.c	\
					ft_strlen.c		\
					ft_memset.c		\
					ft_bzero.c		\
					ft_memcpy.c		\
					ft_memmove.c	\
					ft_strlcpy.c	\
					ft_strlcat.c	\
					ft_toupper.c	\
					ft_tolower.c	\
					ft_strchr.c		\
					ft_strrchr.c	\
					ft_strncmp.c	\
					ft_memchr.c		\
					ft_memcmp.c		\
					ft_strnstr.c	\
					ft_atoi.c		\
					ft_calloc.c		\
					ft_strdup.c		\
			
SRC_PART_2	=       ft_substr.c		\
					ft_strjoin.c	\
					ft_strtrim.c	\
					ft_split.c		\
					ft_itoa.c		\
					ft_strmapi.c	\
					ft_striteri.c	\
					ft_putchar_fd.c	\
					ft_putstr_fd.c	\
					ft_putendl_fd.c	\
					ft_putnbr_fd.c	\

SRC_PART_BONUS =    ft_lstnew.c			\
					ft_lstadd_front.c	\
					ft_lstsize.c		\
					ft_lstlast.c		\
					ft_lstadd_back.c	\
					ft_lstdelone.c		\
					ft_lstclear.c		\
					ft_lstiter.c		\
					ft_lstmap.c			\

SRCS			=	$(SRC_PART_1) 		\
					$(SRC_PART_2) 		\

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRC_PART_BONUS:.c=.o)

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