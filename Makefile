NAME	=	LNXEntropy

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I. -g3

SRC		=	./main.c\
			./sources/devices_parser.c
OBJ		=	$(SRC:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

all : $(NAME)

GNL:
	make -C ./lib/gnl

$(NAME): GNL $(OBJ)
	$(CC) $(OBJ) lib/gnl/gnl.a -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
