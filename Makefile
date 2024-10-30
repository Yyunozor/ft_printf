# Variables
NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRC_DIR		= src
OBJ_DIR		= obj
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
INCLUDES	= -I. -I$(LIBFT_DIR)

# Source files
SRC_FILES	= ft_printf.c \
			  x_char.c \
			  x_str.c \
			  x_ptr.c \
			  x_int.c \
			  x_uint.c \
			  x_hex.c \
			  x_mod.c

# Bonus files
BONUS_FILES	= x_bonus.c

# Paths for source and object files
SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Define LIBFT_OBJS by finding all object files in libft's obj directory
LIBFT_OBJS = $(wildcard $(LIBFT_DIR)/*.o)

# Main rule
all: $(NAME)

# Compile the main library
$(NAME): $(OBJS) $(LIBFT)
	@echo "Creating $(NAME)"
	@ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS) >/dev/null 2>&1
	@ranlib $(NAME) >/dev/null 2>&1

# Bonus target
bonus: $(OBJS) $(BONUS_OBJS) $(LIBFT)
	@echo "Creating $(NAME) with bonus"
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS) $(LIBFT_OBJS) >/dev/null 2>&1
	@ranlib $(NAME) >/dev/null 2>&1

# Compile libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiled $< to $@"

# Create object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean object files and test binary
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C $(LIBFT_DIR) clean

# Remove all generated files, including the library
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re
