# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_2                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smakni <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 09:14:14 by smakni            #+#    #+#              #
#    Updated: 2019/02/23 14:54:09 by vrenaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

CC				=	gcc

CFLAGS			+=	-Wall -Werror -Wextra -O3 -flto -march=native 

CPPFLAGS		=	-I include

AR				=	ar rc

SRC_PATH		=	src

SRC_PATH_P		=	src_p

OBJ_PATH		=	obj

OBJ_PATH_P		=	obj_p

SRC_NAME		=	ft_putchar.c \
					ft_putstr.c \
					ft_putnbr.c \
					ft_sort_int_tab.c \
					ft_revsort_int_tab.c \
					ft_strlen.c	\
		   			ft_strdup.c \
					ft_strcmp.c \
					ft_strncmp.c \
					ft_strcpy.c \
					ft_strncpy.c \
					ft_strcat.c \
					ft_strncat.c \
					ft_memalloc.c \
					ft_tablen.c \
					ft_delete_tab.c \
					ft_memset.c	\
					ft_bzero.c \
					ft_memcpy.c \
					ft_memccpy.c \
					ft_memmove.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_isdigit.c \
					ft_isnumber.c \
					ft_isascii.c \
					ft_isalpha.c \
					ft_isalnum.c \
					ft_strstr.c \
					ft_strnstr.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_isprint.c \
					ft_memdel.c	\
					ft_strnew.c	\
					ft_strdel.c	\
					ft_strclr.c	\
					ft_striter.c \
					ft_striteri.c \
					ft_strmap.c \
					ft_strmapi.c \
					ft_strequ.c \
					ft_strnequ.c \
					ft_strsub.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_strsplit.c \
					ft_putendl.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_itoa.c \
					ft_power.c \
					ft_lstnew.c \
					ft_lstdelone.c \
					ft_lstdel.c \
					ft_lstadd.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_lstmove_last.c \
					ft_llast.c \
					ft_strtoupper.c \
					ft_atoi.c \
					ft_strlcat.c \
					ft_strtolower.c \
					ft_sqrt.c \
					ft_factorial.c \
					ft_print_bits.c \
					ft_strsub_free.c \
					ft_strjoin_free.c \
					ft_strlen_c.c \
					ft_strlen_from.c \
					ft_memset_from.c \
					ft_itoa_li.c \
					ft_itoa_lli.c \
					ft_itoa_imax.c \
					ft_itoa_it.c \
					ft_itoa_ui.c \
					ft_itoa_lui.c \
					ft_itoa_llui.c \
					ft_itoa_uit.c \
					ft_itoa_base.c \
					ft_itoa_base_ui.c \
					ft_itoa_base_llui.c \
					ft_itoa_base_lui.c \
					ft_itoa_base_it.c \
					ft_itoa_base_uit.c \
					ft_putchar2.c \
					ft_putchar1.c \
					ft_putchar3.c \
					ft_putchar4.c \
					ft_memjoin.c \
					ft_memcpy_from.c \
					ft_putstr_printf.c \
					ft_itoa_sit.c \
					ft_strjoin_2free.c \
					ft_strjoin_free1.c \
					get_next_line.c \
					ft_tabdel.c \
					ft_strcpy_from.c

SRC_NAME_P		=	ft_printf.c \
					ft_dprintf.c \
					ft_aux.c \
					check.c \
					check_2.c \
					analyse.c \
					conversion_c.c \
					conversion_f.c \
					conversion_f0.c \
					conversion_d0.c \
					conversion_d.c	\
					conversion_d2.c \
					conversion_d3.c \
					conversion_s.c	\
					conversion_bs.c \
					conversion_p.c \
					conversion_x.c \
					conversion_x1.c \
					conversion_0.c	\
					conversion_none.c \
					ft_putchar_printf.c

OBJ_NAME		=	$(SRC_NAME:.c=.o)

OBJ_NAME_P		=	$(SRC_NAME_P:.c=.o)

SRC 			= 	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

SRC_P 			= 	$(addprefix $(SRC_PATH_P)/,$(SRC_NAME_P))

OBJ 			= 	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ_P 			= 	$(addprefix $(OBJ_PATH_P)/,$(OBJ_NAME_P))

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_P)
		$(AR) $(NAME) $(OBJ) $(OBJ_P)
		ranlib $(NAME)
		@echo "[LIBFT OK]"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH_P)/%.o: $(SRC_PATH_P)/%.c
	@mkdir $(OBJ_PATH_P) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ) $(OBJ_P) 
	rmdir $(OBJ_PATH) 2> /dev/null || true
	rmdir $(OBJ_PATH_P) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: 
	make fclean
	make

.PHONY: all, clean, fclean, re

norme:
	norminette $(SRC)
	norminette $(SRC_P)
	norminette ./include











