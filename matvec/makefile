# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/06 10:11:48 by jwolf             #+#    #+#              #
#    Updated: 2018/08/24 08:22:59 by jwolf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmatvec.a

CFLAGS += -Wextra -Wall

ATTACH =

C = gcc

HEADERS = includes

DIR_S = srcs

DIR_O = obj

SOURCES = mat_rot.c determinant.c determinant2.c matrix.c vec.c vec2.c vec3.c \
			vec4.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
OBJECTS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

$(DIR_O)/%.o:		$(DIR_S)/%.c
	@echo "\033[1;35;m[Compiling $<] \t\033[0m"
	@$(C) $(FLAGS) -I./$(HEADER) -o $@ -c $<

$(NAME): temporary $(OBJECTS)
	@echo "\033[1;30;m[Linking]\033[0m"
	@ar rcs $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "\033[1;30;m[Linked]\033[0m"

all: $(NAME)
	@echo "\033[1;30;m[Compiled]\033[0m"

temporary:
	@mkdir -p $(DIR_O)

clean:
	@echo "\033[1;34;m[Cleaning]\033[0m"
	@rm -rf $(OBJS)
	@rm -rf $(DIR_O)
	@echo "\033[1;34;m[Cleaned]\033[0m"

fclean: clean
	@echo "\033[1;33;m[Cleaning All]\033[0m"
	@rm -rf $(NAME)
	@echo "\033[1;32;m[Cleaned All]\033[0m"

re: fclean clean all
	@echo "\033[1;31;m[Recompiled]\033[0m"

.PHONY: fclean clean all re
