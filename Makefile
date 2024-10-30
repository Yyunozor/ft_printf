# Project name and compiler settings
NAME		= libftprintf.a 
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Directories
SRC_DIR		= src
OBJ_DIR		= obj

# Source files
SRC_FILES	= ft_printf.c x_char.c x_str.c x_ptr.c x_int.c x_uint.c x_hex.c x_mod.c

# Bonus files
BONUS_CONV_FILES = x_bonus.c

# Full paths
SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
			  $(addprefix $(CONV_DIR)/, $(CONV_FILES)) \
			  $(addprefix $(UTIL_DIR)/, $(UTIL_FILES))

BONUS_SRCS = $(addprefix $(CONV_DIR)/, $(BONUS_CONV_FILES))

# Object files
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)

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

# Bonus rule
bonus: $(OBJ_DIR) $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

# Phony targets
.PHONY: all clean fclean re bonus
