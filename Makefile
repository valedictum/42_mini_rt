# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tday <tday@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/19 19:36:12 by tday              #+#    #+#              #
#    Updated: 2024/07/19 22:03:33 by tday             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME 			:=		mini_rt
SRC_DIRS 		:=		src/main src/initialisation src/frame src/controls		\
						src/window
INC_DIR 		:=		inc
MLX_DIR			:=		mlx_linux
LIBFT_DIR		:=		libft
LIBFT			:=		$(LIBFT_DIR)/libft.a
CC				:=		gcc
CFLAGS			:=		-Wall -Wextra -Werror -O3
MLX_FLAGS		:=		-L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
SRCS			:=		$(addprefix src/main/, main.c)							\
						$(addprefix src/initialisation/, init.c)				\
						$(addprefix src/frame/, frame.c)						\
						$(addprefix src/controls/, controls.c)					\
						$(addprefix src/window/, window.c)
OBJS			:=		$(SRCS:.c=.o)
RM				:=		rm -f

# Function definition
define check_dir_change
$(eval CUR_DIR := $(patsubst src/%/,%, $(dir $(1))))
$(if $(filter-out $(LAST_DIR),$(CUR_DIR)), @echo 								\
"$(GREEN)$(CUR_DIR) functions compiled successfully!$(DEFAULT_COLOUR)")
$(eval LAST_DIR := $(CUR_DIR))
endef

# Colours

DEFAULT_COLOUR	:=		\033[0m
GRAY			:=		\033[1;30m
RED				:=		\033[1;31m
GREEN			:=		\033[1;32m
YELLOW			:=		\033[1;33m
BLUE			:=		\033[1;34m
MAGENTA			:=		\033[1;35m
CYAN			:=		\033[1;36m
WHITE			:=		\033[1;37m

# Targets

all: $(NAME)

$(NAME): 		$(LIBFT) $(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) -I$(INC_DIR) -L$(LIBFT_DIR) -lft -I$(MLX_DIR) $(MLX_FLAGS)	-o $(NAME)
				@echo "$(CYAN)Everything compiled and linked into executable: $(BLUE)$(NAME)$(DEFAULT_COLOUR)"
				@echo "\n"

$(LIBFT):		
				@$(MAKE) -s -C $(LIBFT_DIR)

$(OBJS):		%.o: %.c
				@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -c $< -o $@
				@$(call check_dir_change,$<)

clean:			
				@$(RM) $(OBJS)
				@$(foreach dir,$(SRC_DIRS),echo "$(MAGENTA)$(notdir 			\
				$(patsubst %/,%,$(dir))) object files deleted.					\
				$(DEFAULT_COLOUR)";)

fclean: 		
				@$(MAKE) fclean -s -C $(LIBFT_DIR)
				@$(MAKE) -s clean
				@$(RM) $(NAME)
				@echo "$(YELLOW)$(NAME) deleted.$(DEFAULT_COLOUR)"
				@echo "\n"

re: 			fclean all

.PHONY: 		all clean fclean re