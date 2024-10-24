# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epinaud <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 16:30:14 by epinaud           #+#    #+#              #
#    Updated: 2024/10/23 02:13:11 by epinaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -ggdb3

INCLUDES = -I. -Ilibft -Ilibft/printf

LDLIBS = -Llibft -ft

OBJ_DIR = .obj

$(OBJ_DIR)/%.o : %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

all: libft $(OBJ_DIR) $(EXE)

$(EXE) :
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

push_swap: .obj/push_swap.o

libft:
	@git -C libft pull
	@make -C libft

relibft:
	@git -C libft pull
	@make re -C libft

.obj:
	mkdir -p .obj

clean:
	@rm -f $(EXE)
	@make clean -C libft

fclean:  clean
	@rm -rf $(OBJ_DIR)
	@make fclean -C libft

re: fclean relibft $(OBJ_DIR) $(EXE)

.PHONY:  all clean fclean re bonus libft relibft
