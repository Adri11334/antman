##
## EPITECH PROJECT, 2022
## bs_antman
## File description:
## Makefile
##

all:
	make -C ./antman
	make -C ./giantman
.PHONY: all

clean:
	make -s -C ./antman clean
	make -s -C ./giantman clean
.PHONY: clean

fclean:	clean
	make -s -C ./antman fclean
	make -s -C ./giantman fclean
.PHONY: fclean

tests_run:
	make -C ./antman tests_run
	make -C ./giantman tests_run
.PHONY: tests_run

cover:
	make -C ./antman cover
	make -C ./giantman cover
.PHONY: cover

my_tests:	tests_run cover
.PHONY: my_tests

re:	fclean all
.PHONY: re
