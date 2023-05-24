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
	@for i in $(SRC); do make -C $$i clean; done
	make -C tests clean

fclean:	clean
	@for i in $(SRC); do make -C $$i fclean; done
	make -C tests fclean

tests_run:
	make -C tests/ re
	clear
	-./unit_tests

re:	fclean all

.PHONY: all clean fclean re tests_run
