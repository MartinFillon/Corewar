##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile
##

CC = gcc

SRC_ASM = ../asm/src/

SRC = 	$(SRC_ASM)header/parse_write_header.c 			\
		$(SRC_ASM)header/find_prog_size.c 				\
		$(SRC_ASM)body/parse_body.c						\
		$(SRC_ASM)body/direct_params.c 					\
		$(SRC_ASM)body/indirect_params.c 				\
		$(SRC_ASM)body/instruction_parameter.c			\
		$(SRC_ASM)labels/parse_labels.c					\
		$(SRC_ASM)labels/label_address.c 				\
		$(SRC_ASM)error_handling/handle_errors.c		\
		$(SRC_ASM)error_handling/impossible_labels.c	\
		$(SRC_ASM)error_handling/base_actions.c 		\
		$(SRC_ASM)error_handling/fork_actions.c			\
		$(SRC_ASM)error_handling/arithmetic_bitwise.c	\
		$(SRC_ASM)error_handling/load_values_ld.c 		\
		$(SRC_ASM)error_handling/stores_value_st.c 		\
		$(SRC_ASM)error_handling/header.c				\
		$(SRC_ASM)create_file.c							\
		$(SRC_ASM)utils_asm.c							\
		$(SRC_ASM)parser.c

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
