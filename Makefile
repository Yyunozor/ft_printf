# Variables
NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRC_DIR		= src
OBJ_DIR		= obj
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
INCLUDES	= -I. -I$(LIBFT_DIR)
MAKE		= /Applications/Xcode.app/Contents/Developer/usr/bin/make  # Keep your MAKE variable

# Source files
SRC_FILES	= $(wildcard $(SRC_DIR)/*.c)
X_FILES		= $(wildcard $(SRC_DIR)/x_files/*.c)
MAIN_SRCS	= $(SRC_FILES) $(X_FILES)
ALL_SRCS	= $(MAIN_SRCS) $(BONUS_FILES)

# Object files
MAIN_OBJS	= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
MAIN_OBJS	+= $(patsubst $(SRC_DIR)/x_files/%.c,$(OBJ_DIR)/x_files/%.o,$(X_FILES))
ALL_OBJS	= $(MAIN_OBJS) $(BONUS_OBJS)

# Libft object files
LIBFT_OBJS	= $(wildcard $(LIBFT_DIR)/*.o)

# Main rule
all: $(LIBFT) $(NAME)

bonus: all

# Compile the main library
$(NAME): $(MAIN_OBJS)
	@echo "Creating $(NAME)"
	@ar rcs $(NAME) $(MAIN_OBJS) $(LIBFT_OBJS)
	@echo "$(NAME) has been created."

# Compile the library with bonus files
$(NAME)_bonus: $(ALL_OBJS)
	@echo "Creating $(NAME) with bonus files"
	@ar rcs $(NAME) $(ALL_OBJS) $(LIBFT_OBJS)
	@echo "$(NAME) with bonus files has been created."

# Compile libft without showing the full path
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Object file compilation rules with enforced fixed-width for consistent alignment
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@start_time=$$(date +%s); \
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@; \
	end_time=$$(date +%s); \
	printf "\033[1;30m%-15s\033[0m \033[1;37m%-40s\033[0m \033[1;32m✔️\033[0m    |\n" "Compiling:" "$<"; \
	printf "\033[1;37m%-15s\033[0m \033[1;37m%-40s\033[0m \033[1;30m[.o]   |\033[0m\n" "➜ Output:" "$@"; \
	echo "\033[1;37m──────────────────────────────────────────────────────────────|\033[0m"

$(OBJ_DIR)/conversions/%.o: $(SRC_DIR)/x_files/%.c
	@mkdir -p $(@D)
	@start_time=$$(date +%s); \
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@; \
	end_time=$$(date +%s); \
	printf "\033[1;30m%-15s\033[0m \033[1;37m%-40s\033[0m \033[1;32m✔️\033[0m    |\n" "Compiling:" "$<"; \
	printf "\033[1;37m%-15s\033[0m \033[1;37m%-40s\033[0m \033[1;30m[.o]   |\033[0m\n" "➜ Output:" "$@"; \
	echo "\033[1;37m──────────────────────────────────────────────────────────────|\033[0m"

$(OBJ_DIR)/bonus/%.o: $(SRC_DIR)/bonus/%.c
	@mkdir -p $(@D)
	@start_time=$$(date +%s); \
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@; \
	end_time=$$(date +%s); \
	printf "\033[1;30m%-15s\033[0m \033[1;37m%-40s\033[0m \033[1;32m✔️\033[0m    |\n" "Compiling:" "$<"; \
	printf "\033[1;37m%-15s\033[0m \033[1;37m%-40s\033[0m \033[1;30m[.o]   |\033[0m\n" "➜ Output:" "$@"; \
	echo "\033[1;37m──────────────────────────────────────────────────────────────|\033[0m"

# Clean object files
clean:
	rm -f $(MAIN_OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Object files have been removed."

# Remove all generated files, including the library
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(NAME) has been removed."

# Rebuild everything
re: fclean all

# Compile and run the main test file
main: all
	$(CC) $(CFLAGS) $(INCLUDES) -o main tests/main.c $(NAME) $(LIBFT)
	@echo "Running main tests..."
	./main

# Phony targets
.PHONY: all clean fclean re main bonus
