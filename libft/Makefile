# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 17:28:47 by mely-pan          #+#    #+#              #
#    Updated: 2024/12/09 17:29:49 by mely-pan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Source files
SRC = SRC/ft_atoi.c SRC/ft_split.c SRC/ft_isdigit.c SRC/ft_strlcpy.c \
	SRC/ft_strlen.c

# Object files
OBJS = $(SRC:%.c=%.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Library name
NAME = libft.a

# Archive command
AR = ar rcs

# ANSI color codes
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RED = \033[0;31m
NC = \033[0m  # No Color (reset)

# Targets
all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(YELLOW)Creating static library: $(NAME)$(NC)"
	@echo "$(GREEN)SRC files are compiled and library is ready.$(NC)"

$(OBJS): %.o: %.c
	@echo "$(BLUE)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning up libft's object files...$(NC)"
	@ rm -rf $(OBJS)

fclean: clean
	@echo "$(RED)Removing libft's static library: $(NAME)$(NC)"
	@ rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re