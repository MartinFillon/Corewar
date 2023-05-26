##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile for corewar
##

CC	=	gcc

SRC = 	src/main.c								\
		src/utils.c								\
		src/op.c								\
		src/vm/vm.c								\
		src/vm/load_programs.c					\
		src/vm/order_programs.c					\
		src/vm/dump_memory.c					\
		src/vm/run_cycles.c						\
		src/vm/run_cycle.c						\
		src/vm/alive.c							\
		src/executors/getters/get_direct.c		\
		src/executors/getters/get_arg.c			\
		src/executors/getters/get_arg_types.c	\
		src/executors/getters/get_indirect.c	\
		src/executors/writers/write_int.c		\
		src/executors/writers/read_int.c		\
		src/executors/add.c						\
		src/executors/aff.c						\
		src/executors/and.c						\
		src/executors/fork.c					\
		src/executors/ld.c						\
		src/executors/ldi.c						\
		src/executors/lfork.c					\
		src/executors/live.c					\
		src/executors/lld.c						\
		src/executors/lldi.c					\
		src/executors/or.c						\
		src/executors/st.c						\
		src/executors/sti.c						\
		src/executors/sub.c						\
		src/executors/xor.c						\
		src/executors/zjmp.c					\
		src/executors/utils.c					\
		src/arguments/parse_arguments.c			\
		src/arguments/parse_argv.c				\
		src/programs/check_program.c			\
		src/programs/programs.c					\
		src/programs/utils.c					\
		src/programs/read_program.c

NAME = corewar

OBJ = $(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra -Werror
CPPFLAGS	+=	-I../../include
LDFLAGS		+=	-L../../lib
LDLIBS		+=	-lmy

ifeq ($(DEBUG),1)
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
