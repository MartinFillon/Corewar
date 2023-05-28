##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile for asm
##

CC	?=	gcc

SRC	=	$(addprefix src/, main.c						\
			create_file.c								\
			utils_asm.c										\
			parser.c 									\
			header/parse_write_header.c 				\
			header/find_prog_size.c 					\
			body/parse_body.c							\
			body/direct_params.c 						\
			body/indirect_params.c 						\
			body/instruction_parameter.c				\
			labels/parse_labels.c						\
			labels/label_address.c 						\
			error_handling/handle_errors.c				\
			error_handling/impossible_labels.c			\
			error_handling/base_actions.c 				\
			error_handling/fork_actions.c				\
			error_handling/arithmetic_bitwise.c			\
			error_handling/load_values_ld.c 			\
			error_handling/stores_value_st.c 			\
			error_handling/header.c)

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
