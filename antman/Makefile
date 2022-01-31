##
## EPITECH PROJECT, 2022
## bs_antman
## File description:
## Makefile
##


SRC	=	src/antman.c					\
		src/picture_manager.c			\
		src/text_file/free.c			\
		src/text_file/get_words.c		\
		src/text_file/manager.c			\
		src/text_file/output.c			\
		src/text_file/replace_words.c	\
		src/text_file/text_occurence.c	\

CRITERION	=	$(wildcard tests/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	antman

CFLAGS	+=	-W -Wall -Wextra -Werror -Wshadow -Wimplicit -pedantic

CPPFLAGS	+=	-L../lib -lmy
CPPFLAGS	+=	-I./include/
CPPFLAGS	+=	-I../include/
CPPFLAGS	+=	-g

all:	lib	$(NAME)
.PHONY: all

lib:
	make -C ../lib/my
.PHONY: lib

$(NAME):	$(OBJ)
		gcc src/main.c $^ -o $@ -ggdb3 $(LDFLAGS) $(CPPFLAGS)

tests_run:	CPPFLAGS += --coverage
tests_run:	CPPFLAGS += -lcriterion
tests_run:	lib
	gcc -o uts $(SRC) $(CRITERION) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
	@-./uts
	@rm -f uts
.PHONY: tests_run

cover:
	@mkdir -p criterions_r
	@gcovr --exclude tests/ --html --html-details -o criterions_r/cover.html
	@gcovr --branches --exclude tests/
	@make -C ./ clean
.PHONY: cover

clean:
	make -s -C ../lib/my clean
	@find . -type f | xargs touch
	@rm -f $(OBJ)
	@rm -f *.o
	@rm -f *~
	@rm -f vgcore*
	@rm -f #*
	@rm -f *.gcda
	@rm -f *.identifier
	@rm -f *.gcno
.PHONY: clean

fclean:	clean
	make -s -C ../lib/my fclean
	rm -f $(NAME)
	@rm -f criterions_r/*.html
	@rm -f criterions_r/*.css
	@rm -rf criterions_r/
	@rm -f *Zone.Identifier
	@rm -f projet
.PHONY: fclean

my_tests: tests_run cover
.PHONY: my_tests

re:	fclean all
.PHONY: re