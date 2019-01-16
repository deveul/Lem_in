# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrenaudi <urenaudi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 14:25:25 by vrenaudi          #+#    #+#              #
#    Updated: 2018/12/13 17:45:49 by vrenaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

NAME = libft.a

SRCS = ./printf/ft_printf.c ./printf/ft_get_fmt.c ./printf/ft_conv_c.c \
	   ./printf/ft_conv_d.c ./printf/ft_conv_h.c ./printf/ft_conv_o.c \
	   ./printf/ft_conv_s.c ./printf/ft_conv_u.c ./printf/ft_conv_p.c \
	   ./printf/ft_conv_per.c ./printf/ft_useful.c ./printf/ft_conv_wc.c \
	   ./printf/ft_init_struct.c ./printf/ft_get_type.c ./printf/ft_conv_ws.c \
	   ./printf/ft_conv_error.c ./printf/ft_conv_b.c ./printf/ft_get_conv.c \
	   ./printf/ft_dprintf.c \
	   ./libft/ft_atoi.c ./libft/ft_bzero.c ./libft/ft_isalnum.c \
	   ./libft/ft_isalpha.c ./libft/ft_isascii.c ./libft/ft_isdigit.c \
	   ./libft/ft_isprint.c ./libft/ft_itoa.c ./libft/ft_memalloc.c \
	   ./libft/ft_memccpy.c ./libft/ft_memchr.c ./libft/ft_memcmp.c \
 	   ./libft/ft_memcpy.c ./libft/ft_memdel.c ./libft/ft_memmove.c \
	   ./libft/ft_memset.c ./libft/ft_putchar.c ./libft/ft_putchar_fd.c \
	   ./libft/ft_putendl.c ./libft/ft_putendl_fd.c ./libft/ft_putnbr.c \
	   ./libft/ft_putnbr_fd.c ./libft/ft_putstr.c ./libft/ft_putstr_fd.c \
	   ./libft/ft_strclr.c ./libft/ft_strcmp.c ./libft/ft_strcpy.c \
	   ./libft/ft_strdel.c ./libft/ft_strdup.c ./libft/ft_strequ.c \
	   ./libft/ft_striter.c ./libft/ft_striteri.c ./libft/ft_strjoin.c \
	   ./libft/ft_strnjoin.c ./libft/ft_strlcat.c ./libft/ft_strlen.c \
 	   ./libft/ft_strmap.c ./libft/ft_strmapi.c ./libft/ft_strncat.c \
	   ./libft/ft_strncmp.c ./libft/ft_strncpy.c ./libft/ft_strnequ.c \
	   ./libft/ft_strnew.c ./libft/ft_strnstr.c ./libft/ft_strrchr.c \
	   ./libft/ft_strsplit.c ./libft/ft_strstr.c ./libft/ft_strsub.c \
	   ./libft/ft_strtrim.c ./libft/ft_tolower.c ./libft/ft_toupper.c \
	   ./libft/ft_lstnew.c ./libft/ft_lstadd.c ./libft/ft_lstiter.c \
	   ./libft/ft_lstdelone.c ./libft/ft_lstdel.c ./libft/ft_lstmap.c \
	   ./libft/ft_intlen.c ./libft/ft_strtoupper.c ./libft/ft_strtolower.c \
 	   ./libft/ft_swapbits.c ./libft/ft_printbits.c ./libft/ft_reversebits.c \
	   ./libft/ft_strcat.c ./libft/ft_strchr.c ./libft/ft_strlenuntilc.c \
	   ./libft/ft_lstaddlast.c ./libft/ft_strndup.c ./libft/ft_lstrmvone.c \
	   ./libft/ft_strjoinfree.c ./libft/ft_uns_itoa.c ./libft/ft_unsintlen.c \
 	   ./libft/ft_dec_to_octa.c ./libft/ft_dec_to_hex.c \
	   ./libft/ft_uintmax_to_hex.c ./libft/ft_strrpc.c ./libft/ft_lololen.c \
	   ./libft/ft_itoa_ll.c ./libft/ft_unslololen.c ./libft/ft_uns_itoa_ll.c \
	   ./libft/ft_strjoinfreeall.c ./libft/ft_strjoinfreesec.c \
 	   ./libft/ft_dec_to_bi.c ./libft/ft_power.c ./libft/ft_bi_to_dec.c \
	   ./libft/ft_strrpcall.c ./libft/ft_putwchar.c ./libft/ft_putwstr.c \
	   ./libft/ft_wstrlen.c ./libft/ft_charlen.c ./libft/ft_putwcinstr.c \
	   ./libft/ft_strjoinuntilc.c ./libft/ft_memjoin.c \
	   ./libft/ft_memjoinfreeall.c ./libft/ft_putmemstr.c ./libft/ft_memdup.c \
 	   ./libft/ft_strlct.c ./libft/ft_strjoinone.c ./libft/ft_dectobi_ll.c \
	   ./libft/get_next_line.c

OBJ = $(SRCS:.c=.o)

HEAD = -I ./libft/. -I ./printf/.

RL = ranlib

RM = rm -f

AR = ar rc

%.o: %.c $(HEAD)
	$(CC) $(HEAD) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(RL) $(NAME)

clean:
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re: fclean all
