# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 12:46:00 by mel-habi          #+#    #+#              #
#    Updated: 2024/10/09 15:55:41 by mel-habi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= cub3D
LIBFT			= libft
MLX				= mlx_linux

PARSER_SRCS		= checkers.c parser.c
UTILS_SRCS		= char_utils.c free_utils.c gc.c print_utils.c
MAIN_SRCS		= cub3D.c
				  
SOURCES			= $(addprefix srcs/parser/, $(PARSER_SRCS)) \
				  $(addprefix srcs/utils/, $(UTILS_SRCS)) \
 				  $(addprefix srcs/, $(MAIN_SRCS))
OBJECTS			= $(SOURCES:.c=.o)

HEADERS_FILES	= cub3D.h parser.h utils.h
HEADERS			= $(addprefix includes/, $(HEADERS_FILES))
FLAGS 			= -Wall -Wextra -Werror -g3
LIBS			= -L$(LIBFT) -lft -I$(LIBFT) -L$(MLX) -l$(MLX) -L/usr/lib -I$(MLX) -lXext -lX11 -lm -lz
OPTIONS 		= -I$(LIBFT) -I includes -I $(MLX)

#################################################################################

RED 	 = '\033[0;31m'
GREEN 	 = '\033[0;32m'
YELLOW 	 = '\033[0;33m'
BLUE 	 = '\033[0;34m'
PURPLE 	 = '\033[0;35m'
NC 		 = '\033[0m'

#################################################################################

%.o: %.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(OPTIONS) $< -o $@
	@echo $(GREEN)✅ $< compiled! $(NC)

$(NAME): $(LIBFT)/$(LIBFT).a $(MLX) $(OBJECTS) $(HEADERS)
	@$(CC) $(FLAGS) $(OPTIONS) -o $@ $(OBJECTS) $(LIBS)
	@echo $(BLUE)✅ $@ built! $(NC)

all: $(NAME)

clean:
	@rm -f $(OBJECTS)
	@rm -rf $(MLX)
	@make clean -C $(LIBFT)
	@echo $(YELLOW)🗑️ $(MLX) $(LIBFT) $(OBJECTS) deleted! $(NC)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo $(RED)🗑️ $(NAME) deleted! $(NC)

re: fclean all

$(LIBFT)/$(LIBFT).a:
	@make -C $(LIBFT)
	@echo $(PURPLE)✅ $@ compiled! $(NC)

$(MLX): 
	@git clone https://github.com/42Paris/minilibx-linux.git $@
	@make -C $@
	@cp $(MLX)/libmlx_Linux.a $(MLX)/lib$(MLX).a 
	@echo $(PURPLE)✅ $@ compiled! $(NC)

.PHONY: all clean fclean re
