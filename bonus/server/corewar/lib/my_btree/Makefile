##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_btree
##

CC	=	gcc
RM	=	rm -f

INCLUDE	=	-I../../include

SRC	=	./add.c			\
		./create.c		\
		./free.c		\
		./find.c

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
	$(RM) $(OBJ)

re:	clean all

.PHONY: all clean re
