##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile
##

CC = gcc

SRC_DIR = ../corewar/

SRC = 	$(SRC_DIR)src/utils.c								\
		$(SRC_DIR)src/op.c								\
		$(SRC_DIR)src/vm/vm.c								\
		$(SRC_DIR)src/vm/load_programs.c					\
		$(SRC_DIR)src/vm/order_programs.c					\
		$(SRC_DIR)src/vm/dump_memory.c					\
		$(SRC_DIR)src/vm/run_cycles.c						\
		$(SRC_DIR)src/executors/getters/get_direct.c		\
		$(SRC_DIR)src/executors/getters/get_arg.c			\
		$(SRC_DIR)src/executors/getters/get_arg_types.c	\
		$(SRC_DIR)src/executors/getters/get_indirect.c	\
		$(SRC_DIR)src/executors/writers/write_int.c		\
		$(SRC_DIR)src/executors/add.c						\
		$(SRC_DIR)src/executors/aff.c						\
		$(SRC_DIR)src/executors/and.c						\
		$(SRC_DIR)src/executors/fork.c					\
		$(SRC_DIR)src/executors/ld.c						\
		$(SRC_DIR)src/executors/ldi.c						\
		$(SRC_DIR)src/executors/lfork.c					\
		$(SRC_DIR)src/executors/live.c					\
		$(SRC_DIR)src/executors/lld.c						\
		$(SRC_DIR)src/executors/lldi.c					\
		$(SRC_DIR)src/executors/or.c						\
		$(SRC_DIR)src/executors/st.c						\
		$(SRC_DIR)src/executors/sti.c						\
		$(SRC_DIR)src/executors/sub.c						\
		$(SRC_DIR)src/executors/xor.c						\
		$(SRC_DIR)src/executors/zjmp.c					\
		$(SRC_DIR)src/arguments/parse_arguments.c			\
		$(SRC_DIR)src/arguments/parse_argv.c				\
		$(SRC_DIR)src/programs/check_program.c			\
		$(SRC_DIR)src/programs/programs.c					\
		$(SRC_DIR)src/programs/read_program.c

TESTS 	=	instructions_tester.c

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
