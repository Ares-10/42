NAME = Animal

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = incluude/

SRCS =	main.cpp		\
		Animal.cpp		\
		Dog.cpp			\
		Cat.cpp			\
		WrongAnimal.cpp	\
		WrongCat.cpp	\

OBJS = $(SRCS:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC			=	$(addprefix $(SRC_DIR), $(SRCS))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJS))

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(CPPFLAGS) $^ -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	mkdir -p $(OBJ_DIR)
	c++ $(CPPFLAGS) -c $< -o $@ -I $(INC_DIR)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re