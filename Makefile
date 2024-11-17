# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epinaud <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 16:30:14 by epinaud           #+#    #+#              #
#    Updated: 2024/11/17 16:43:07 by epinaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

INCLUDES = -I. -Ilibft -Ilibft/printf

LDLIBS = -Llibft -lft 

OBJ_DIR = .obj

OS_NAME := $(shell uname -s | tr A-Z a-z)

$(OBJ_DIR)/%.o : %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

all: ftbranch libft $(OBJ_DIR) $(EXE)

$(EXE) :
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

os:
	@echo $(OS_NAME)

push_swap: .obj/push_swap.o .obj/stack_push.o .obj/stack_rotate.o \
			.obj/stack_swap.o .obj/utils.o .obj/lst_sorting.o .obj/lst_parsing.o \
			.obj/args_parsing.o

libft:
	@make -C libft

relibft:
	@make re -C libft

.obj:
	@mkdir -p .obj

ftbranch:
	@git -C libft checkout main

clean:
	@rm -f $(EXE)
	@make clean -C libft

fclean:  clean
	@rm -rf $(OBJ_DIR)
	@make fclean -C libft

re: ftbranch fclean relibft $(OBJ_DIR) $(EXE)

.PHONY:  all clean fclean re bonus libft relibft
