CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME	:= so_long
LIBMLX	:= ./MLX42
LIBFT = ./libft/libft.a
INCLUDE = -I./include
GREEN   := \033[32;1m
RESET	= \x1b[0m
SRC_DIR = srcs/
OBJ_DIR = objs/

SRCS = so_long.c utils.c

SRC	= $(addprefix $(SRC_DIR), $(SRCS))
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all:	check_MLX42_dir	$(NAME)

$(NAME): $(LIBFT) libmlx $(OBJ)
	@echo "Compiled with $(GREEN)$(CFLAGS)$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	@$(MAKE) -C ./Libft
	@echo "$(GREEN) Libft compiled ✅$(RESET)"

libmlx:
	@cd $(LIBMLX) && cmake -B build && cmake --build build -j4
	@echo "$(GREEN) MLX42 built ✅ $(RESET)"

check_MLX42_dir:
	@if ! [ -d "$(LIBMLX)" ]; then \
	git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); \
	fi

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

clean: 
	@$(MAKE) clean -C ./libft
	@echo "$(GREEN) Cleaned ✅ $(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@echo "$(GREEN) Full cleaned ✅ $(RESET)"
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
