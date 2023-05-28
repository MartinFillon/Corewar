##
## EPITECH PROJECT, 2022
## my_lib
## File description:
## Makefile for my_lib
##

# Modules available:
# my_network my_file my_math my_map
# my_list my_stdio my_fmt
# my_stdlib my_vec my_str my_cstr

# Modules to use:
LIB	=	my_json	my_list my_fmt my_stdio \
		my_stdlib my_btree my_map my_vec \
		my_str my_cstr

NAME	=	libmy.a

all:
	@for i in $(LIB); do make -C $$i; done

clean:
	@for i in $(LIB); do make -C $$i clean; done

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
