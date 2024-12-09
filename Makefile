
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
SOURCES = s21_string.c test_s21.c

all: s21_string.a

s21_string.o: s21_string.c
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c s21_string.c -o s21_string.o 

test_s21.o: test_s21.c
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c test_s21.c -o test_s21.o

s21_string.a: s21_string.o test_s21.o
	@ar rc libstring.a s21_string.o test_s21.o
	@ranlib libstring.a
	@$(CC) $(CFLAGS) $(GCOV_FLAGS) main.c -L. -lstring -o s21_tests -lcheck -lsubunit -lm 

test: s21_string.a
	@./s21_tests

gcov_report: s21_string.a test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory report

clean:
	rm -rf s21_tests
	rm -rf *.gcda *.gcno *.info *.o *.a report

clang: $(SOURCES) 
	clang-format --style=Google -i *.c
