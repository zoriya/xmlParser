##
## EPITECH PROJECT, 2019
## xmlparser
## File description:
## Makefile
##

SRC = src/xmlparser.c \
	src/parsenode.c \
	src/list_utility.c

OBJ = $(SRC:%.c=%.o)

INCLUDE = -I ./include

CFLAGS = $(INCLUDE) -Wall -Wextra -Wshadow

LDFLAGS = 

CC = gcc

AR = ar rc

NAME = xmlparser.a

all: build

build: $(OBJ)
	$(AR) $(NAME) $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

dbg: CFLAGS += -g
dbg: re

.PHONY: all build clean fclean
