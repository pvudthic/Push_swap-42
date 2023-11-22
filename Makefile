NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra

SRC =	push_swap.c \
		./src/sort/sort_number.c \
		./src/sort/sort.c \
		./src/stack/push.c \
		./src/stack/reverse_rotate.c \
		./src/stack/rotate.c \
		./src/stack/stack_create.c \
		./src/stack/swap.c \
		./src/utility/utility.c \
		./src/utility/stack_utility.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean all

.PHONY: all clean fclean re
