##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile for asm
##

CC	=	gcc

SRC	=	src/main.c							\
		src/create_file.c					\
		src/parser/parser.c					\
		src/parser/body.c					\
		src/parser/instruction_parameter.c	\
		src/error_handling/handle_errors.c	\
		src/error_handling/big_endian.c

NAME = asm

OBJ = $(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra -Werror
CPPFLAGS	+=	-I../include
LDFLAGS		+=	-L../lib
LDLIBS		+=	-lmy

ifeq ($(DEBUG),1)
	CC = clang
	CFLAGS += -g3 -fsanitize=address
	LDFLAGS += -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
