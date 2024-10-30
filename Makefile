# Variables
NAME        = libftprintf.a
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
SRC_DIR     = src
OBJ_DIR     = obj
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
INCLUDES    = -I. -I$(LIBFT_DIR)

# Source files
SRC_FILES   = $(wildcard $(SRC_DIR)/*.c)
CONV_FILES  = $(wildcard $(SRC_DIR)/conversions/*.c)
SRCS        = $(SRC_FILES) $(CONV_FILES)

# Object files
OBJS        = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
OBJS       += $(patsubst $(SRC_DIR)/conversions/%.c,$(OBJ_DIR)/conversions/%.o,$(CONV_FILES))

# Libft object files
LIBFT_OBJS  = $(wildcard $(LIBFT_DIR)/*.o)

# Main rule
all: $(NAME)

# Compile the main library
$(NAME): $(OBJS) $(LIBFT)
	@echo "Creating $(NAME)"
	@ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)
	@echo "$(NAME) has been created."

# Compile libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Object file compilation rules
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiled $< into $@"

$(OBJ_DIR)/conversions/%.o: $(SRC_DIR)/conversions/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiled $< into $@"

# Clean object files
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Object files have been removed."

# Remove all generated files, including the library
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(NAME) has been removed."

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
