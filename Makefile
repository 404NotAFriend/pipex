# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/29 06:37:20 by bramalho@st       #+#    #+#              #
#    Updated: 2026/01/29 16:12:26 by bramalho@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   NAMES                                      #
# **************************************************************************** #

NAME		= pipex

# **************************************************************************** #
#                                 COMPILER                                     #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g

# **************************************************************************** #
#                                DIRECTORIES                                   #
# **************************************************************************** #

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes

LIBFT_DIR	= libft
PRINTF_DIR	= ft_printf
GNL_DIR		= GNL

# **************************************************************************** #
#                                  FILES                                       #
# **************************************************************************** #

# 1. Common Files (Used by BOTH Mandatory and Bonus)
COMMON_SRCS	= $(SRC_DIR)/parsing.c \
				$(SRC_DIR)/execute.c \
				$(SRC_DIR)/utils.c \
				$(SRC_DIR)/cleanup.c

# 2. Mandatory Specific (Strictly 2 args)
MAND_SRCS	= $(SRC_DIR)/pipex.c

# 3. Bonus Specific (Loop + Here_doc)
# Note: here_doc.c goes HERE, not in mandatory!
BONUS_SRCS	= $(SRC_DIR)/pipex_bonus.c \
				$(SRC_DIR)/here_doc.c

# 4. GNL (Needed for Bonus)
GNL_SRCS	= $(GNL_DIR)/get_next_line.c \
				$(GNL_DIR)/get_next_line_utils.c

# **************************************************************************** #
#                               OBJECTS                                        #
# **************************************************************************** #

COMMON_OBJS	= $(COMMON_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
MAND_OBJS	= $(MAND_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS	= $(BONUS_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
GNL_OBJS	= $(GNL_SRCS:$(GNL_DIR)/%.c=$(OBJ_DIR)/%.o)

# **************************************************************************** #
#                                 LIBRARIES                                    #
# **************************************************************************** #

LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF		= $(PRINTF_DIR)/libftprintf.a

# **************************************************************************** #
#                                  FLAGS                                       #
# **************************************************************************** #

INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR)
LIBS		= -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

# **************************************************************************** #
#                                  COLORS                                      #
# **************************************************************************** #

GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

# **************************************************************************** #
#                                  RULES                                       #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(COMMON_OBJS) $(MAND_OBJS)
	@$(CC) $(CFLAGS) $(COMMON_OBJS) $(MAND_OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)✅ pipex (Mandatory) compiled successfully!$(RESET)"

# **************************************************************************** #
#                                  BONUS                                       #
# **************************************************************************** #

bonus: .bonus

.bonus: $(LIBFT) $(PRINTF) $(COMMON_OBJS) $(BONUS_OBJS) $(GNL_OBJS)
	@$(CC) $(CFLAGS) $(COMMON_OBJS) $(BONUS_OBJS) $(GNL_OBJS) $(LIBS) -o $(NAME)
	@touch .bonus
	@echo "$(GREEN)✅ pipex (Bonus) compiled successfully!$(RESET)"

# **************************************************************************** #
#                                  COMPILATION                                       #
# **************************************************************************** #

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

$(PRINTF):
	@make -C $(PRINTF_DIR) --no-print-directory

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiled: $<$(RESET)"

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiled: $<$(RESET)"

# **************************************************************************** #
#                                  CLEANUP                                       #
# **************************************************************************** #

clean:
	@rm -rf $(OBJ_DIR) .bonus
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@make -C $(PRINTF_DIR) clean --no-print-directory
	@echo "$(RED)🗑️  Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@make -C $(PRINTF_DIR) fclean --no-print-directory
	@echo "$(RED)🗑️  Executables removed$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re
