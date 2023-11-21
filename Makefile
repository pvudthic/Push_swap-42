NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra

SRC =	push_swap.c \
		sort_number.c \
		tiny_sort.c \
		stack_create.c \
		stack_utility.c \
		swap.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		utility.c

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
