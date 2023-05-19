##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile for corewar
##

CC	=	gcc

SRC = 	src/main.c							\
		src/utils.c							\
		src/vm/vm.c							\
		src/vm/load_programs.c				\
		src/vm/order_programs.c				\
		src/vm/dump_memory.c				\
		src/arguments/parse_arguments.c		\
		src/arguments/parse_argv.c			\
		src/programs/check_program.c		\
		src/programs/programs.c				\
		src/programs/utils.c				\
		src/programs/read_program.c

NAME = corewar

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
