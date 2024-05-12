CC = gcc
FLAGS = -Wall -Wextra -Werror --std=c11
TEST_FLAGS = -fprofile-arcs -ftest-coverage

SRCS = $(wildcard	$(MAIN_FILES_ANOTHER) \
					$(MAIN_FILES_ARITH) \
					$(MAIN_FILES_COMPARE) \
					$(MAIN_FILES_CONVERT) \
					$(MAIN_FILES_TOOLS))

SRCS_TEST = $(wildcard	$(MAIN_FILES_ANOTHER) \
					$(MAIN_FILES_ARITH) \
					$(MAIN_FILES_COMPARE) \
					$(MAIN_FILES_CONVERT) \
					$(MAIN_FILES_TOOLS) \
					$(MAIN_FILES_TESTS))

SRC_FILES = $(filter-out testing.c, $(SRCS))
OBJS=$(SRC_FILES:.c=.o)
OBJ_FILES = $(filter-out test.o, $(OBJS))
LIB=`pkg-config --libs gtk+-3.0`
LDFLAGS=-g2

MAIN_FILES_TOOLS =	$(wildcard	tools/set/*.c \
								tools/get/get_decimal_bit.c \
                                tools/get/get_decimal_power.c \
                                tools/get/get_decimal_sign.c \
								tools/math_helper/*.c \
								tools/set/*.h \
								tools/get/*.h \
								tools/math_helper/*.h)
MAIN_FILES_ARITH =	$(wildcard	arithmetic_operators/*.c \
								arithmetic_operators/*.h)
MAIN_FILES_COMPARE = $(wildcard operators_comparison/*.c \
								operators_comparison/*.h)
MAIN_FILES_CONVERT = $(wildcard converters/*.c \
								converters/*.h)
MAIN_FILES_ANOTHER = $(wildcard another_functions/*.c \
								another_functions/*.h)
MAIN_FILES_TESTS = $(wildcard	united_tests/*.c \
								united_tests/*.h)
MAIN_FILES_MANUAL = $(wildcard manual_test/*.c)
MAIN_OBJ_FILES_MANUAL = $(wildcard trash/*.h.gch trash/*.o)

TRASH_FILES = $(wildcard	arithmetic_operators/*.o operators_comparison/*.o converters/*.o \
							another_functions/*.o tests/*.o tools/set/*.o tools/get/*.o \
							tools/math_helper/*.o arithmetic_operators/*.h.gch \
							operators_comparison/*.h.gch converters/*.h.gch \
							another_functions/*.h.gch tests/*.h.gch tools/set/*.h.gch \
							tools/get/*.h.gch tools/math_helper/*.h.gch)

rwildcard = $(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

all: $(OBJS) decimal.a

test: $(SRCS_TEST)
	@$(CC) -o $@ $(TEST_FLAGS) `pkg-config --cflags --libs check` $(SRCS_TEST)
	@./test

decimal.a:
	$(CC) $(FLAGS) -c $(SRCS)
	@ar rc $@ ./*.o
	ranlib $@
#	cp $@ lib$@

GCNO_F = ./*.gcno

gcov_report: test
	@gcov $(GCNO_F) -m
	@lcov -t "gcov_report" -o gcov_report.info -c -d .
	@genhtml -o ./ gcov_report.info
	@open ./index-sort-f.html

clang:
	@clang-format --style=Google -n	*.h $(MAIN_FILES_ARITH) \
 									$(MAIN_FILES_TOOLS) \
 									$(MAIN_FILES_COMPARE) \
 									$(MAIN_FILES_CONVERT) \
 									$(MAIN_FILES_ANOTHER) \
 									$(MAIN_FILES_TESTS) \
 									$(MAIN_FILES_MANUAL)
style:
	@clang-format --style=Google -i *.h $(MAIN_FILES_ARITH) \
										$(MAIN_FILES_TOOLS) \
										$(MAIN_FILES_COMPARE) \
										$(MAIN_FILES_CONVERT) \
										$(MAIN_FILES_ANOTHER) \
										$(MAIN_FILES_MANUAL) \
										$(MAIN_FILES_TESTS)

.PHONY: clean decimal.a gcov_report clang test
clean:
	@rm -rf decimal.a *.o *.gcno *.gcov *.gcda test \
		*.png *.html cmd_line *.css *.info ./src *.out \
		*.h.gch $(TRASH_FILES) trash/*.o trash/*.h.gch \
		./united_tests/testing.o \
		$(call rwildcard,.,*.html)
