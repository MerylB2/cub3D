# NAME 		:= cub3d

# CC 			:= cc
# CFLAGS 		:= -Wall -Wextra -Werror

# SRCDIR 		:= srcs
# INCDIR 		:= includes
# OBJDIR 		:= obj

# # Source files organized by module
# MAIN_SRCS 	:= main.c
# INIT_SRCS 	:= init/game.c init/init_mlx.c init/textures.c
# PARSER_SRCS := parser/parser_config.c parser/parser_validation.c parser/parser_map.c parser/parser.c
# RAYC_SRCS 	:= raycasting/raycast.c raycasting/dda.c raycasting/render.c raycasting/textures.c
# CTLS_SRCS 	:= controls/key_hooks.c controls/movements.c controls/rotation.c
# UTILS_SRCS 	:= utils/get_next_line.c utils/utils2.c utils/error.c utils/utils1.c utils/free.c
# EXIT_SRCS 	:= exit/exit_game.c

# SOURCES 	:= $(MAIN_SRCS) $(INIT_SRCS) $(PARSER_SRCS) $(RAY_SRCS) $(CTLS_SRCS) $(UTILS_SRCS) $(EXIT_SRCS)
# SRCS 		:= $(addprefix $(SRCDIR)/, $(SOURCES))
# OBJS 		:= $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))

# MLX_DIR 	:= /home/cmetee-b/minilibx-linux
# MLX_LIB 	:= $(MLX_DIR)/libmlx.a
# MLX_FLAGS 	:= -L$(MLX_DIR) -lmlx -lXext -lX11

# RED			:= \033[1;31m
# GREEN		:= \033[1;32m
# YELLOW		:= \033[1;33m
# BLUE		:= \033[1;34m
# RESET		:= \033[0m

# all: $(MLX_LIB) $(NAME)

# $(NAME): $(OBJDIR) $(OBJS)
# 	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
# 	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -lm -o $(NAME)
# 	@echo "$(GREEN)$(NAME)-> Build successful ✅$(RESET)"

# $(OBJDIR)/%.o: $(SRCDIR)/%.c
# 	@echo "$(YELLOW)Compiling $<...$(RESET)"
# 	@mkdir -p $(dir $@)
# 	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(MLX_DIR) -c $< -o $@

# $(OBJDIR):
# 	@mkdir -p $(OBJDIR)
# 	@mkdir -p $(OBJDIR)/init
# 	@mkdir -p $(OBJDIR)/parser
# 	@mkdir -p $(OBJDIR)/raycasting
# 	@mkdir -p $(OBJDIR)/controls
# 	@mkdir -p $(OBJDIR)/utils
# 	@mkdir -p $(OBJDIR)/exit


# $(MLX_LIB):
# 	@echo "$(YELLOW)Compiling MLX...$(RESET)"
# 	@make -C $(MLX_DIR)

# clean:
# 	@echo "$(RED)Cleaning objects files...$(RESET)"
# 	@rm -rf $(OBJDIR)
# 	@make -C $(MLX_DIR) clean
# 	@echo "$(GREEN)Objects cleaned ✅$(RESET)"

# fclean: clean
# 	@echo "$(RED)Removing $(NAME)...$(RESET)
# 	@rm -f $(NAME)
# 	@echo "$(GREEN)Full clean done!✅$(RESET)"

# re: fclean all

# norme:
# 	@clear
# 	@norminette | grep "Error" || echo "$(GREEN)Norme OK ✅$(RESET)"

# # Additional rules for development
# debug: CFLAGS += -g
# debug: re

# # Optimized build with maximum optimizations
# optimize: CFLAGS += -O3 -march=native -flto
# optimize: re

# .PHONY: all clean fclean re norme debug optimize


NAME        = cub3D

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g3
INCLUDES    = -I./includes -I./mlx
LIBS        = -L./mlx -lmlx -lXext -lX11 -lm
# Pour macOS, utiliser:
# LIBS      = -L./mlx -lmlx -framework OpenGL -framework AppKit -lm

SRCS        = srcs/main.c \
              srcs/init/init_game.c \
              srcs/init/init_mlx.c \
              srcs/init/init_textures.c \
              srcs/parser/parser.c \
              srcs/parser/parser_config.c \
              srcs/parser/parser_map.c \
              srcs/parser/parser_validation.c \
              srcs/raycasting/raycast.c \
              srcs/raycasting/dda.c \
              srcs/raycasting/textures.c \
              srcs/raycasting/render.c \
              srcs/controls/key_hooks.c \
              srcs/controls/movements.c \
              srcs/controls/rotation.c \
              srcs/utils/utils1.c \
              srcs/utils/utils2.c \
              srcs/utils/get_next_line.c \
              srcs/utils/error.c \
              srcs/utils/free.c \
              srcs/exit/exit_game.c

OBJS        = $(SRCS:.c=.o)

# Colors
GREEN       = \033[0;32m
RED         = \033[0;31m
BLUE        = \033[0;34m
NC          = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Compiling $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -f $(OBJS)
	@echo "$(GREEN)Clean done!$(NC)"

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(NC)"
	@rm -f $(NAME)
	@echo "$(GREEN)Full clean done!$(NC)"

re: fclean all

.PHONY: all clean fclean re