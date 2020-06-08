# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/08 08:32:48 by pntsunts          #+#    #+#              #
#    Updated: 2020/06/08 09:09:13 by pntsunts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAGS = -Wall -Wextra -Werror

SRC = printrev.c ft_ls.c recur.c sion.c ft_ls_a.c ft_checkf.c ft_confirm.c ft_ls_a.c  printr.c ft_printl.c ft_isdir.c ft_time.c

OBJ = $(SRC:.c=.o)

$(NAME):
	@gcc -c $(SRC) $(FLAGS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@rm -rf $(OBJ)

all: $(NAME)

clean:
	@rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)

c:
	@gcc $(FLAGS) main.c libft/libft.a $(NAME) -o ft_ls

re: fclean all

N: 
	norminette
