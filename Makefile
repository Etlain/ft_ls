# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 09:06:02 by mmouhssi          #+#    #+#              #
#*   Updated: 2016/09/16 22:58:33 by mmouhssi         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LIB = libft/libft.a

SRC =	ft_param.c ft_putls.c ft_range.c ft_tab.c main.c ft_struct.c \
	ft_putdirl.c fill_struct_l.c ft_putcolor.c ft_putformat.c last_namep.c \

PATH_SRC = sources/

FLAGS = -Wall -Wextra -Werror

LIBFT = -C libft/

all: $(NAME)

$(NAME):
	make $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(addprefix $(PATH_SRC), $(SRC)) $(LIB)

clean :
	make clean $(LIBFT)

fclean:
	make fclean $(LIBFT)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
