##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile
##

SRC = asm corewar lib

all:
	@for i in $(SRC); do make -C $$i; done

clean:
	@for i in $(SRC); do make -C $$i clean >/dev/null; done

fclean:	clean
	@for i in $(SRC); do make -C $$i fclean >/dev/null; done

re:	fclean all

.PHONY: all clean fclean re
