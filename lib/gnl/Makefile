NAME	=	gnl.a

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I. -g3

SRC		=	$(wildcard *.c)
OBJ		=	$(SRC:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

all : $(NAME)

$(NAME):  $(OBJ)
	ar rcs $@ $^

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
