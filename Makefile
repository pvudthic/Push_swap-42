NAME = push_swap
CC = cc
CFLAG = -Wall -Werror -Wextra

SRC =	push_swap.c \
		sort_number.c \
		stack_operation.c \
		utility.c


all : $(NAME)

$(NAME) :
	$(CC) $(CFLAG) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
