##
## EPITECH PROJECT, 2019
## xmlparser
## File description:
## Makefile
##

SRC = src/xmlparser.c \
	src/parsenode.c \
	src/list_utility.c \
	src/helper.c \
	src/xmlproperties.c \
	src/rawnode.c \
	src/xml_destroy.c \
	src/xmlget.c

OBJ = $(SRC:%.c=%.o)

TESTS = tests/test_basics.c \
	tests/tests_realxml.c

TEST_MAIN = tests/test_main.c

COVERAGE = --coverage -lcriterion

INCLUDE = -I ./include

CFLAGS = $(INCLUDE) -Wall -Wextra -Wshadow

LDFLAGS = -lmy -L lib/my/

CC = gcc

AR = ar rc

NAME = libxmlparser.a

UT = ./ut

FT = ./ft

all: build

build: $(OBJ)
	$(AR) $(NAME) $(OBJ)

tests_run:
	$(CC) -o $(UT) $(SRC) $(TESTS) $(COVERAGE) $(CFLAGS) $(LDFLAGS)
	$(UT)

clean:
	$(RM) $(OBJ)
	$(RM) *.gc*

fclean: clean
	$(RM) $(NAME)
	$(RM) $(UT)
	$(RM) $(FT)

re: fclean all

dbg: CFLAGS += -g
dbg: fclean
dbg: $(OBJ)
	$(CC) -o $(FT) $(SRC) $(TEST_MAIN) $(CFLAGS) $(LDFLAGS)

.PHONY: all build clean fclean
