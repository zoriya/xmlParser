##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Lib makefile
##

SRC = *.c

OBJ = *.o \
	*.gc*

LIBOBJ = lib/my/*.o \
	lib/my/libmy.a \
	include/my.h

all: buildlib

buildlib:
	gcc -c ./*.c
	ar rc ./libmy.a ./*.o
	ar rc ../libmy.a ./*.o

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(LIBOBJ)
	rm -f libmy.a
	rm -f ../libmy.a

re: fclean all
