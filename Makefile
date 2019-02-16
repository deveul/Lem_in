# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 13:20:28 by smakni            #+#    #+#              #
#    Updated: 2019/02/16 13:04:11 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lem-in

CC			=	gcc

CFLAGS		+=	-Wall -Werror -Wextra -g3 

CPPFLAGS	=	-I include -I libft/include
				
SRC_PATH	=	src

OBJ_PATH	=	obj

LDFLAGS		=	-L libft

LDLIBS		=	-lft

SRC_NAME	=	main.c \
				print_env.c \
				fill.c \
				read_data.c \
				fill_matrice.c \
				handle_memory.c \
				create_rooms.c \
				dijkstra.c \
				aff_data_dij.c \
				check_path_list.c \
				update_matrice.c \
				fill_combinations.c

OBJ_NAME	=	$(SRC_NAME:.c=.o)

SRC 		= 	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ 		= 	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ) 
		make -C libft
		$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

sanitize: 
		make -C libft
		$(CC) -fsanitize=address -g3 $(LDFLAGS) $(LDLIBS) $(OBJ) -o lem-in

resanitize: fclean $(OBJ) 
		make -C libft
		$(CC) -fsanitize=address -g3 $(LDFLAGS) $(LDLIBS) $(OBJ) -o lem-in

clean:
	rm -fv $(OBJ)
	rmdir $(OBJ_PATH) 2> /dev/null || true
	make clean -C libft

fclean: clean
	rm -fv $(NAME)
	make fclean -C libft

re:
	make fclean
	make

.PHONY: all, clean, fclean, re

norme:
	norminette $(SRC)
	norminette ./include
