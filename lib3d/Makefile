#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 09:49:07 by rbenjami          #+#    #+#              #
#    Updated: 2013/11/20 11:31:21 by rbenjami         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

include		Makefile.sources

NAME		=	lib3d.a

CFLAGS		=	-Wall -Wextra -Werror -O3

OBJ_LIB		=	$(SRC_LIB:.c=.o)

HEAD		=	lib3d.h

all:		$(NAME)

$(NAME):	$(OBJ_LIB)
	@ar -rc ../$(NAME) $(OBJ_LIB)
	@ranlib ../$(NAME)
	@echo ""
	@printf "\n\033[33mCompilation of %s: \033[32mSuccess \t\033[34m[\033[32m✔\033[34m]\n\033[0m" $(NAME)

$(OBJ_LIB):		$(HEAD)

%.o:		%.c
	@echo -n _
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@printf "\033[31mObjects of %s : deleted\n\033[0m" $(NAME)
	@/bin/rm -f $(OBJ_LIB)

fclean:		clean
	@printf "\033[31m%s : deleted\n\033[0m" $(NAME)
	@/bin/rm -f ../$(NAME)

re:			fclean all

.PHONY:		all re fclean clean
