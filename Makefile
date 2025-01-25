# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epinaud <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 16:30:14 by epinaud           #+#    #+#              #
#    Updated: 2025/01/25 22:59:25 by epinaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c args_parsing.c premade_sort.c sort_preprocessing.c \
	lst_parsing.c lst_sorting.c stack_swap.c stack_push.c \
	stack_rotate.c stack_reverse_rotate.c

EXE = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I. -Ilibft/includes

LDLIBS = -Llibft -lft 

OBJ_DIR = .obj

$(OBJ_DIR)/%.o : %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

all: ftbranch libft $(OBJ_DIR) $(EXE)

$(EXE) :
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

push_swap: $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

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

.PHONY:  all clean fclean re libft relibft
