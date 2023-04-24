##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile
##

SRC = src/main.c

NAME = asm

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -Werror
CPPFLAGS += -Iinclude
LDLIBS += -L../lib
LDFLAGS += -lmy

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDLIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
