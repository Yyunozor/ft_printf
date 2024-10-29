# Project name and compiler settings
NAME		= libftprintf.a 
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Directories
SRC_DIR		= src
CONV_DIR	= $(SRC_DIR)/conversions
UTIL_DIR	= $(SRC_DIR)/utils
OBJ_DIR		= obj

# Source files
SRC_FILES	= ft_printf.c
CONV_FILES	= handle_char.c handle_string.c handle_pointer.c \
			  handle_integer.c handle_unsigned.c handle_hex.c handle_percent.c
UTIL_FILES	= ft_itoa_base.c ft_putnbr.c ft_putchar.c ft_putstr.c

# Full paths
SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
			  $(addprefix $(CONV_DIR)/, $(CONV_FILES)) \
			  $(addprefix $(UTIL_DIR)/, $(UTIL_FILES))

# Object files
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Main rules
all: $(NAME)

# Create object directory and compile
$(NAME): $(OBJ_DIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(SRC_DIR)
	mkdir -p $(OBJ_DIR)/$(CONV_DIR)
	mkdir -p $(OBJ_DIR)/$(UTIL_DIR)

# Compile source files
$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rules
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Bonus rule (placeholder for future bonus implementations)
bonus: all

# Phony targets
.PHONY: all clean fclean re bonus

