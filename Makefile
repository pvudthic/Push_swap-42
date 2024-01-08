NAME 			= push_swap
CHECKER			= checker
CC 				= gcc
CFLAGS			= -Wall -Werror -Wextra -Iinc -Isrc -Ilibft
LIBFT_DIR		= libft
LIBFT_FILE		= $(LIBFT_DIR)/libft.a
SRC_DIR			= src
OBJ_DIR			= obj


VPATH = $(SRC_DIR) $(SRC_DIR)/mem_handle $(SRC_DIR)/instruction $(SRC_DIR)/stack $(SRC_DIR)/sort $(SRC_DIR)/sort/sort_big $(SRC_DIR)/checker

STACK_SRC		=	stack.c \
					stack_util.c \
					mem_alloc.c \
					mem_free.c \
					error_handle.c \

INS_SRC			=	push.c \
					reverse_rotate.c \
					rotate.c \
					swap.c \
					show_output.c

PUSH_SWAP_SRC	=	$(STACK_SRC) \
					push_swap.c \
					$(INS_SRC) \
					base_sort.c \
					sort3_position_1.c \
					sort3_position_2.c \
					sort3_position_3.c \
					sort3_position_4.c \
					sort3_position_util.c \
					partition_position.c \
					partition_move.c \
					original_quick_sort.c \
					create_rank.c \
					original_quick_sort_util.c \
					sort_small.c \
					sort_util.c \
					sort.c \

CHECKER_SRC		=	$(STACK_SRC) \
					$(INS_SRC) \
					checker.c \
					checker_util.c

PUSH_SWAP_OBJ	=	$(PUSH_SWAP_SRC:%.c=obj/%.o)
CHECKER_OBJ		=	$(CHECKER_SRC:%.c=obj/checker/%.o)

$(NAME): $(LIBFT_FILE) $(PUSH_SWAP_OBJ)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) $(LIBFT_FILE) -o $@

$(LIBFT_FILE):
	$(MAKE) -C $(LIBFT_DIR)

$(PUSH_SWAP_OBJ): $(OBJ_DIR)/%.o: %.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

$(CHECKER): $(CHECKER_OBJ)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) $(LIBFT_FILE) -o $@

$(CHECKER_OBJ): obj/checker/%.o: %.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(CHECKER)

obj:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/checker

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f checker
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
