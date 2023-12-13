NAME 				= push_swap
CC 					= cc
FLAGS 				= -Wall -Werror -Wextra -Iinc -Isrc

VPATH				=	src:src/stack:src/sort:src/partition:src
PUSH_SWAP_OBJ 		=	$(SRC:%.c=obj/%.o)
SRC					=	push_swap.c \
						debugger.c \
						push.c \
						reverse_rotate.c \
						rotate.c \
						swap.c \
						utility.c \
						free_error.c \
						create_stack.c \
						base_sort.c \
						base_sort_new.c \
						sort3_easy.c \
						sort4_5_easy.c \
						sort3_position_1.c \
						sort3_position_2.c \
						sort3_position_3.c \
						sort3_position_4.c \
						sort_position_util.c \
						easy_sort.c \
						create_rank.c \
						easy_util.c \
						sort_util.c \
						partition.c \
						move.c \
						range_sort_util.c \
						sort.c \

$(NAME)	: $(PUSH_SWAP_OBJ)
	$(CC) $(FLAGS) $(PUSH_SWAP_OBJ) -o $@

$(PUSH_SWAP_OBJ):	obj/%.o: %.c
					@mkdir -p $(dir $@)
					$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

obj:
	mkdir -p obj

clean :
	rm -rf obj

fclean : clean
	rm $(NAME)

re : fclean all

.PHONY: all clean fclean re
