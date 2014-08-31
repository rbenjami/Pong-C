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

NAME		=	libft

CFLAGS		=	-Wall -Wextra -Werror

OBJ_LIB		=	$(SRC_LIB:.c=.o)

HEAD		=	libft.h get_next_line.h

all:		$(NAME)

$(NAME):	$(OBJ_LIB)
	@ar -rc ../$(NAME).a $(OBJ_LIB)
	@ranlib ../$(NAME).a
	@printf "\n\033[33mCompilation of %s: \033[32mSuccess \t\033[34m[\033[32m✔\033[34m]\n\033[0m" $(NAME)

$(OBJ_LIB):	$(HEAD)

%.o:		%.c
	@echo -n _
	@$(CC) $(CFLAGS) -I. -c $< -o $@ $(INC)

clean:
	@printf "\033[31mObjects of libft.a : deleted\n\033[0m"
	@/bin/rm -f $(OBJ_LIB)

fclean:		clean
	@printf "\033[31mlibft.a : deleted\n\033[0m"
	@/bin/rm -f ../$(NAME).a

re:		fclean all

norm:		$(SRC_LIB) $(HEAD)
	@printf "\033[31mNORME $(NAME)\n\033[0m":
	@norminette $^

.PHONY:		all re fclean clean norm
