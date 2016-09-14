# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 09:06:02 by mmouhssi          #+#    #+#              #
#*   Updated: 2016/01/19 17:31:31 by mmouhssi         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LIB = libft/libft.a

SRC = ft_param.c ft_putls.c ft_range.c ft_tab.c main.c \
	  ft_struct.c ft_putdirl.c fill_struct_l.c

PATH_SRC = sources/

FLAGS = -Wall -Wextra -Werror

LIBFT = -C libft/

all: 
	make $(LIBFT)
	gcc -g -o $(NAME) $(addprefix $(PATH_SRC), $(SRC)) $(LIB)

clean :
	make clean $(LIBFT)

fclean:
	make fclean $(LIBFT)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
