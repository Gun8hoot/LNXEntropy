NAME	=	LNXEntropy

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I. -g3

SRC		=	sources/main.c\
			sources/structure.c\
			sources/threads.c\
			sources/init.c\
			sources/devices_parser.c\
			sources/signal_handler.c\
			sources/safety.c

OBJ		=	$(SRC:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

all : $(NAME)

GNL:
	make -C ./lib/gnl

$(NAME): GNL $(OBJ)
	$(CC) $(OBJ) lib/gnl/gnl.a -o $@

clean :
	make clean -C ./lib/gnl
	rm -f $(OBJ)

fclean : clean
	make fclean -C ./lib/gnl
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
