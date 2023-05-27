##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile
##

CC = gcc

SRC_ASM = ../asm/

SRC = 	$(SRC_ASM)src/header/parse_write_header.c 		\
		$(SRC_ASM)src/header/find_prog_size.c 			\
		$(SRC_ASM)src/body/parse_body.c					\
		$(SRC_ASM)src/body/direct_params.c 				\
		$(SRC_ASM)src/body/indirect_params.c 			\
		$(SRC_ASM)src/body/instruction_parameter.c		\
		$(SRC_ASM)src/labels/parse_labels.c				\
		$(SRC_ASM)src/labels/label_address.c 			\
		$(SRC_ASM)src/error_handling/handle_errors.c	\
		$(SRC_ASM)src/error_handling/impossible_labels.c\
		$(SRC_ASM)src/error_handling/base_actions.c 	\
		$(SRC_ASM)src/error_handling/fork_actions.c		\
		$(SRC_ASM)src/error_handling/arithmetic_bitwise.c\
		$(SRC_ASM)src/error_handling/load_values_ld.c 	\
		$(SRC_ASM)src/error_handling/stores_value_st.c 	\
		$(SRC_ASM)src/error_handling/header.c			\
		$(SRC_ASM)src/create_file.c						\
		$(SRC_ASM)src/utils_asm.c						\
		$(SRC_ASM)src/parser.c

TESTS 	=	asm_tester.c

LDLIBS 		+= -lcriterion -lgcov --coverage
CFLAGS		+=	-Wall -Wextra -Werror --coverage
CPPFLAGS	+=	-I../include
LDFLAGS		+=	-L../lib
LDLIBS		+=	-lmy

NAME = ./unit_tests


all: lib $(NAME)

lib:
	make -C ../lib

$(NAME):
	$(CC) $(SRC) $(LDLIBS) $(CFLAGS) -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(TESTS)
	mv $(NAME) ../.

clean:
	rm -f ../*.gcda
	rm -f ../*.gcno
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all
