NAME 			= push_swap
CC 				= gcc
CFLAGS			= -Wall -Werror -Wextra -Iinc -Isrc -Ilibft
LIBFT_DIR		= libft
LIBFT_FILE		= $(LIBFT_DIR)/libft.a
SRC_DIR			= src
OBJ_DIR			= obj
CHECKER			= checker

VPATH = $(SRC_DIR) $(SRC_DIR)/free_mem $(SRC_DIR)/move $(SRC_DIR)/stack $(SRC_DIR)/sort $(SRC_DIR)/sort/sort_big $(SRC_DIR)/sort/sort_small

PUSH_SWAP_SRC	=	push_swap.c \
					free_mem.c \
					push.c \
					reverse_rotate.c \
					rotate.c \
					swap.c \
					stack_util.c \
					create_stack.c \
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
					split_data.c \
					original_quick_sort_util.c \
					sort_small.c \
					sort_util.c \
					sort.c \
					debugger.c

CHECKER_SRC		=	checker.c

PUSH_SWAP_OBJ	=	$(PUSH_SWAP_SRC:%.c=$(OBJ_DIR)/%.o)
CHECKER_OBJ		=	$(CHECKER_SRC:%.c=$(OBJ_DIR)/%.o)

$(NAME): $(LIBFT_FILE) $(PUSH_SWAP_OBJ)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) $(LIBFT_FILE) -o $@

$(LIBFT_FILE):
	$(MAKE) -C $(LIBFT_DIR)

$(PUSH_SWAP_OBJ): $(OBJ_DIR)/%.o: %.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

$(CHECKER): $(CHECKER_OBJ)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) -o $@

$(CHECKER_OBJ): $(OBJ_DIR)/%.o: %.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

# bonus: $(CHECKER)

obj:
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
