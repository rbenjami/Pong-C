export	CC	=	cc

NAME		=	pong

CFLAGS		=	-Wall -Wextra -Werror

SRC_DIR		=	srcs/

OBJ_LIB		=	$(libft/SRC_LIB:.c=.o)

OBJ_LIB_3D	=	$(lib3d/SRC_LIB:.c=.o)

SRC			=	$(addprefix $(SRC_DIR), $(FILES))

OBJ			=	$(SRC:.c=.o)

LIB			=	-L./ -lft -l3d -lncurses

INC			=	-I./libft -I./lib3d

FILES		=	$(NAME).c			\
				game.c				\
				renderEngine.c		\
				coreEngine.c		\
				gameObject.c		\
				lineObject.c

all:		libft.a lib3d.a $(NAME)

libft.a:	libft/$(OBJ_LIB)
	@make -sC libft

lib3d.a:	lib3d/$(OBJ_LIB_3D)
	@make -sC lib3d

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@printf ""
	@printf "\n\033[33mCompilation of %s : \033[32mSuccess\n\033[0m" $(NAME)

%.o:		%.c
	@echo -n _
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@/bin/rm -f $(OBJ)
	@printf "\033[31mObjects of %s : deleted\n\033[0m" $(NAME)

fclean:		clean
	@/bin/rm -f $(NAME)
	@printf "\033[31m$(NAME) : deleted\n\033[0m" $(NAME)
	@make -s fclean -C libft
re:		fclean all

.PHONY:		all clean fclean re
