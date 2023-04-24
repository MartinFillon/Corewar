##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_json
##

CC = gcc

INCLUDE	=	-I../../include


SRC	=	./getters.c						\
		./parse_value.c					\
		./parser.c						\
		./utils.c						\
		./get_va_value.c				\
		./json_get.c					\
		./json_free.c					\
		./json_print.c					\
		./json_stringify.c				\
		./types/parse_array.c			\
		./types/parse_boolean.c			\
		./types/parse_number.c			\
		./types/parse_object.c			\
		./types/parse_string.c


CFLAGS += -Werror -Wextra -Wall
CPPFLAGS += $(INCLUDE)

ifeq ($(DEBUG),1)
	CFLAGS += -g3
endif

OBJ	=	$(SRC:.c=.o)

NAME	=	../libmy.a

all:	$(OBJ)
	@ar cq $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

re:	clean all

.PHONY: all clean re
