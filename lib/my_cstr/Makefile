##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_cstr
##

CC	=	gcc
RM	=	rm -f

INCLUDE	=	-I../../include

SRC	=	./char_infos.c				\
		./char_modifiers.c			\
		./misc.c					\
		./my_strcat.c 				\
		./my_strcpy.c 				\
		./my_strcmp.c 				\
		./my_strdup.c 				\
		./my_strlen.c 				\
		./str_infos.c 				\
		./str_modifiers.c 			\
		./char_infos.c

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
