# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwolf <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/06 10:11:48 by jwolf             #+#    #+#              #
#    Updated: 2018/07/09 06:37:00 by jwolf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS += -Wextra -Wall

ATTACH =

C = gcc

HEADERS = includes

DIR_S = srcs

DIR_O = obj

SOURCES = ft_atoi.c ft_bzero.c ft_clearspace.c ft_intminmax.c ft_isalnum.c \
			ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c \
			ft_isupper.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
			ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c \
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
			ft_memset.c ft_print_memory.c ft_putchar_fd.c ft_putchar.c \
			ft_putendl_c.c ft_putendl_fd.c ft_putendl_i_fd.c ft_putendl_i.c \
			ft_putendl.c ft_putnbr.c ft_putstr.c ft_putstr_fd.c ft_strcat.c \
			ft_strchr.c ft_strlen.c ft_rand.c ft_putnbr_fd.c ft_atoi_base.c\
			ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
			ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
			ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
			ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
			ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c \
			ft_strtrim.c ft_strtrimcpy.c ft_tolower.c ft_toupper.c \
			ft_wordcount.c get_next_line.c ft_ishex.c

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
