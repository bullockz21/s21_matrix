OS := $(shell uname -s)
CC = gcc
FLAG = -Wall -Werror -Wextra
FLAG_C = -c -Wall -Werror -Wextra
CL_11 = -std=c11
ALL_FILE = *.c
ALL_FILE_O = *.o

ifeq ($(OS), Darwin)
		FLAGS_PLATFORM = -lcheck
else
		FLAGS_PLATFORM = -lcheck -lsubunit -lrt -lm -lpthread
endif

all: clean s21_matrix.a

test: s21_matrix.a
	@gcc tests/*.c s21_matrix.a $(FLAGS_PLATFORM) -o tests.o
	@./tests.o

gcov_report:
	$(CC) --coverage $(ALL_FILE) tests/*.c s21_matrix.a $(FLAGS_PLATFORM)  -o gсov_report
	./gсov_report
	lcov -t gcov_report -o lcov_info -c -d .
	genhtml -o report lcov_info
	open ../src/report/index.html
	
s21_matrix.a:
	@$(CC) $(FLAG_C) $(ALL_FILE)
	@ar rcs s21_matrix.a $(ALL_FILE_O)

clean:
	@rm -f *.a
	@rm -f *.o
	@rm -f *.gcda
	@rm -f *.gcdo
	@rm -f *.gcno
	@rm -f *.info
	@rm -f gсov_report
	@rm -rf report
	@rm -f lcov_info

rebuild: all test
