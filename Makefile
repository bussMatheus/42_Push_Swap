# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 17:08:28 by mely-pan          #+#    #+#              #
#    Updated: 2025/01/02 18:49:42 by mely-pan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c manage_input.c clean.c \
	ft_error.c ft_lst.c ft_lst_utils.c \
	p_and_rr_operations.c s_operations.c r_operations.c \
	algorithm.c ft_lst_utils2.c

OBJ = $(SRC:%.c=%.o)

NAME = push_swap

CC = cc
FLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -rf

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# ANSI color codes
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RED = \033[0;31m
NC = \033[0m  # No Color (reset)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Compiled push_swap successfully$(NC)"

#Run libft's makefile in the libft directory
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ): %.o: %.c
	@echo "$(BLUE)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Removing object files: $(NAME)$(NC)"
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Removing static library: $(NAME)$(NC)"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re