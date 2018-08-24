# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/06 10:11:48 by jwolf             #+#    #+#              #
#    Updated: 2018/08/24 12:05:33 by jwolf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

OS   = $(shell uname)

CFLAGS += -Wextra -Wall -I./includes

ATTACH = -L libft/ -lft -L matvec -lmatvec -lmlx \
			-framework OpenGL -framework AppKit -OFast

C = gcc

HEADERS = includes

DIR_S = srcs

DIR_O = obj

SOURCES = main.c draw.c trace.c parse.c objectstuff.c vecs.c color.c \
			extra.c sphericals.c planeicals.c conicals.c cylandricals.c

OBJECTS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

$(DIR_O)/%.o:		$(DIR_S)/%.c $(HEADERS)/$(NAME).h
	@echo "\033[1;35;m[Compiling $<] \t\033[0m"
	@$(C) $(CFLAGS) -c -o $@ $<

$(NAME): temporary $(OBJECTS)
	@echo "\033[1;34;m[Making... Pizza]\033[0m"
	@make -C libft
	@make -C matvec
	$(C) $(CFLAGS) -o $(NAME) $(OBJECTS) $(ATTACH)

all: temporary $(NAME)

temporary:
	@mkdir -p obj

clean:
	@echo "\033[1;33;m[Cleaning]\033[0m"
	@make -C libft clean
	@make -C matvec clean
	@rm -rf $(OBJECTS)

fclean: clean
	@echo "\033[1;32;m[Force Cleaning]\033[0m"
	@make -C libft fclean
	@make -C matvec fclean
	@rm -rf $(NAME)
	@rm -rf $(DIR_O)

re: fclean clean all
	@echo "\033[1;31;m[Recompiled]\033[0m"

run: $(NAME)
	./$(NAME) scene/ex.rtv1 > out

.PHONY: fclean clean all re
