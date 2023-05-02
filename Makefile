##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile
##

SRC = lib asm corewar

all:
	@for i in $(SRC); do make -C $$i; done

clean:
	@for i in $(SRC); do make -C $$i clean >/dev/null; done

fclean:	clean
	@for i in $(SRC); do make -C $$i fclean >/dev/null; done

re:	fclean all

.PHONY: all clean fclean re
