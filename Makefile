# Variables
NAME        = libftprintf.a
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
SRC_DIR     = src
OBJ_DIR     = obj
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
INCLUDES    = -I. -I$(LIBFT_DIR)
MAKE        = /Applications/Xcode.app/Contents/Developer/usr/bin/make

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
all: $(LIBFT) $(NAME)

# Compile the main library
$(NAME): $(OBJS)
	@echo "Creating $(NAME)"
	@ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)
	@echo "$(NAME) has been created."

# Compile libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Object file compilation rules with fancy output
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@start_time=$$(date +%s); \
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@; \
	end_time=$$(date +%s); \
	printf "\033[1;30m%-20s\033[0m\t\033[1;37m%-30s\033[0m\t✔️\n" "Compiling:" "$<"; \
	printf "\033[1;37m%-20s\033[0m\t\033[1;37m%-30s\033[0m\t\033[1;30m[.o]\033[0m\n" "➜ Output:" "$@"; \
	echo "\033[1;37m─────────────────────────────────────────────────────────────\033[0m"

$(OBJ_DIR)/conversions/%.o: $(SRC_DIR)/conversions/%.c
	@mkdir -p $(@D)
	@start_time=$$(date +%s); \
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@; \
	end_time=$$(date +%s); \
	printf "\033[1;30m%-20s\033[0m\t\033[1;37m%-30s\033[0m\t✔️\n" "Compiling:" "$<"; \
	printf "\033[1;37m%-20s\033[0m\t\033[1;37m%-30s\033[0m\t\033[1;30m[.o]\033[0m\n" "➜ Output:" "$@"; \
	echo "\033[1;37m─────────────────────────────────────────────────────────────\033[0m"

# Clean object files and directories
clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Object files and $(OBJ_DIR) directory have been removed."

# Remove all generated files, including the library
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(NAME) has been removed."

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
