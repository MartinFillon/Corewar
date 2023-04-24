##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_stdlib
##

CC = gcc

INCLUDE	=	-I../../include


SRC	=	./my_atoi.c			\
		./my_itoa.c			\
		./my_atof.c			\
		./my_ftoa.c			\
		./my_ftoa_utils.c	\
		./my_fftoa.c		\
		./my_nbrlen.c		\
		./my_alloc.c		\
		./my_memcpy.c		\
		./my_memset.c		\
		./my_memcmp.c		\
		./my_swap.c			\
		./my_free.c

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
