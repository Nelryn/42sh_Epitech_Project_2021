##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make binary
##

SRC	=	$(wildcard src/*.c)

NAME	=	42sh

CFLAGS	+=	-W -Werror -Wall -Wextra

TFLAGS	=	-l criterion --coverage

CFLAGS	+=	-L ./lib/my -lmy

CFLAGS	+=	-I include

UNIT_NAME	=	unit_test

TESTS	=	tests/*.c \
			$(wildcard src/*.c)

all:
	cp include/my.h lib/my/
	cp include/pipe.h lib/my/
	make -j8 -C ./lib/my all
	gcc -o $(NAME) main.c $(SRC) $(CFLAGS) -g -g3

clean:
	make -C ./lib/my clean
	rm -f *~
	rm -f lib/my/my.h
	rm -f lib/my/pipe.h

fclean: clean test_clean
	make -C ./lib/my fclean
	rm -f $(NAME)

re:     fclean all

test_clean:
	rm -rf *.gc*
	rm -rf $(UNIT_NAME)
	rm -rf .vscode

make_test: all test_clean
	gcc -o $(UNIT_NAME) $(TESTS) $(CFLAGS) $(TFLAGS)

tests_run: make_test
	./$(UNIT_NAME) --verbose