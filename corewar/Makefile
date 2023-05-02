##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile
##

SRC = 	src/main.c 							\
		src/arguments/parse_arguments.c

NAME = corewar

CFLAGS += -Wall -Wextra -Werror
CPPFLAGS += -I./include
LDLIBS += -L../lib
LDFLAGS += -lmy

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDLIBS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
