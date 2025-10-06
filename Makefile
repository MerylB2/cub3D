NAME 		:= cub3d

CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror

SRCDIR 		:= srcs
INCDIR 		:= includes
OBJDIR 		:= obj

# Source files organized by module
MAIN_SRCS 	:= main.c
INIT_SRCS 	:= init/init.c init/init_mlx.c init/texture_utils.c
PARSER_SRCS := parser/map_loader.c parser/map_parser.c parser/map_utils.c \
				parser/parser_config.c parser/parser_validation.c parser/cub_parser.c
RAYC_SRCS 	:= raycasting/raycast.c raycasting/dda.c raycasting/render.c raycasting/texture.c
CTLS_SRCS 	:= controls/input.c controls/movement.c controls/rotation.c
UTILS_SRCS 	:= utils/get_next_line.c utils/game_loop.c utils/error.c utils/utils.c utils/free.c
EXIT_SRCS 	:= exit/exit_game.c

SOURCES 	:= $(MAIN_SRCS) $(INIT_SRCS) $(PARSER_SRCS) $(RAY_SRCS) $(CTLS_SRCS) $(UTILS_SRCS) $(EXIT_SRCS)
SRCS 		:= $(addprefix $(SRCDIR)/, $(SOURCES))
OBJS 		:= $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))

MLX_DIR 	:= /home/cmetee-b/minilibx-linux
MLX_LIB 	:= $(MLX_DIR)/libmlx.a
MLX_FLAGS 	:= -L$(MLX_DIR) -lmlx -lXext -lX11

RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
RESET		:= \033[0m

all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -lm -o $(NAME)
	@echo "$(GREEN)$(NAME)-> Build successful ✅$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(MLX_DIR) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/init
	@mkdir -p $(OBJDIR)/parser
	@mkdir -p $(OBJDIR)/raycasting
	@mkdir -p $(OBJDIR)/controls
	@mkdir -p $(OBJDIR)/utils
	@mkdir -p $(OBJDIR)/exit


$(MLX_LIB):
	@echo "$(YELLOW)Compiling MLX...$(RESET)"
	@make -C $(MLX_DIR)

clean:
	@echo "$(RED)Cleaning objects...$(RESET)"
	@rm -rf $(OBJDIR)
	@make -C $(MLX_DIR) clean
	@echo "$(RED)Objects cleaned ✅$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Executable removed ✅$(RESET)"

re: fclean all

norme:
	@clear
	@norminette | grep "Error" || echo "$(GREEN)Norme OK ✅$(RESET)"

# Additional rules for development
debug: CFLAGS += -g
debug: re

# Optimized build with maximum optimizations
optimize: CFLAGS += -O3 -march=native -flto
optimize: re

.PHONY: all clean fclean re norme debug optimize