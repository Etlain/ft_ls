# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 09:06:02 by mmouhssi          #+#    #+#              #
#*   Updated: 2016/09/14 12:04:52 by mmouhssi         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =   conversion/ft_ahtoi.c conversion/ft_atoi.c conversion/ft_base.c		\
	conversion/ft_ctoa.c conversion/ft_itoa.c conversion/ft_itoah.c		\
	conversion/ft_itoao.c conversion/ft_lltoa.c conversion/ft_lltoab.c	\
	conversion/ft_lltoah.c conversion/ft_lltoao.c conversion/ft_ulltoa.c	\
	\
	display/ft_put_error.c display/ft_putchar.c display/ft_putendl.c	\
	display/ft_putendl_tab.c display/ft_putldbl.c display/ft_putnbr.c	\
	display/ft_putnstr.c display/ft_putnwstr.c display/ft_putstr.c		\
	display/ft_putstr_tab.c	display/ft_putwchar.c display/ft_putwstr.c	\
	\
	files/ft_putchar_fd.c files/ft_putendl_fd.c files/ft_putnbr_fd.c	\
	files/ft_putstr_fd.c files/get_next_line.c	\
	\
	is/ft_isalnum.c is/ft_isalpha.c	is/ft_isascii.c	is/ft_isdigit.c		\
	is/ft_isprint.c	\
	\
	list/ft_lstadd.c list/ft_lstdel.c list/ft_lstdelone.c list/ft_lstiter.c	\
	list/ft_lstmap.c list/ft_lstnew.c	\
	\
	math/ft_abs.c math/ft_factorial.c math/ft_nbrlen.c math/ft_power.c	\
	math/ft_sqrt.c	\
	\
	mem/ft_bzero.c mem/ft_memalloc.c mem/ft_memccpy.c mem/ft_memchr.c	\
	mem/ft_memcmp.c	mem/ft_memcpy.c	mem/ft_memdel.c	mem/ft_memmove.c	\
	mem/ft_memset.c	mem/ft_sizebyte.c	\
	\
	other/ft_swap.c other/ft_tolower.c other/ft_toupper.c	\
	\
	string/ft_free_tab.c string/ft_init_str.c string/ft_sizewchar.c		\
	string/ft_strcat.c string/ft_strchr.c string/ft_strclr.c		\
	string/ft_strcmp.c string/ft_strcpy.c string/ft_strdel.c		\
	string/ft_strdup.c string/ft_strequ.c string/ft_striter.c		\
	string/ft_striteri.c string/ft_strjoin.c string/ft_strjoin_path.c 	\
	string/ft_strlcat.c string/ft_strlen.c string/ft_strmap.c		\
	string/ft_strmapi.c string/ft_strncat.c	string/ft_strncmp.c		\
	string/ft_strncpy.c string/ft_strndup.c string/ft_strnequ.c		\
	string/ft_strnew.c string/ft_strnstr.c string/ft_strrchr.c		\
	string/ft_strsplit.c string/ft_strstr.c string/ft_strsub.c 		\
	string/ft_strtrim.c string/ft_wstrlen.c string/ft_wnstrlen.c	\
	\
	ft_printf/add_width.c ft_printf/change_color.c ft_printf/fill_zero.c	\
	ft_printf/ft_format.c ft_printf/ft_is.c	ft_printf/ft_printf.c		\
	ft_printf/ft_sc.c ft_printf/ft_type.c ft_printf/ft_wp.c			\
	ft_printf/no_print.c ft_printf/write_nbr.c	\

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

$(OBJ) :
	gcc -c $(FLAGS) -o $@ $*.c

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
