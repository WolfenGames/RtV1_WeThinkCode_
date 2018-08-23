# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/12 13:11:21 by ibotha            #+#    #+#              #
#    Updated: 2018/08/21 13:37:42 by jwolf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = vectorlib.a
HED = vectorlib.h
OBJ = matrix.o matrixop.o matrixop2.o vector.o vectorio.o vectorop.o vectorrot.o

all: $(NAME)

$(NAME): $(OBJ)
	@echo "[ \x1b[32mLinking... \x1b[0m]"
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "[ \x1b[34mLinked $(NAME) \x1b[0m]\n"

$(OBJ): %.o: %.c $(HED)
	@echo "[ \x1b[32mAdding \x1b[33m$@ \x1b[0m]"
	@gcc -c $*.c -o $@ -Wall -Werror -Wextra

fclean: clean
	@rm -f $(NAME)

clean:
	@rm -f $(OBJ)

re: fclean all

.PHONY: all fclean clean re
