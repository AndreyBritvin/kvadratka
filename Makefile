CC = g++

CFLAGS = -lm -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

all: a.out # double_procedures.o square_solver.o square_unit_test.o mode_parser.o main.o

a.out: main.o double_procedures.o square_solver.o square_unit_test.o mode_parser.o color_output.o
	$(CC) $(CFLAGS) square_solver.o square_unit_test.o double_procedures.o mode_parser.o main.o color_output.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

square_solver.o: square_solver.cpp
	$(CC) $(CFLAGS) -c square_solver.cpp

square_unit_test.o: square_unit_test.cpp
	$(CC) $(CFLAGS) -c square_unit_test.cpp

double_procedures.o: double_procedures.cpp
	$(CC) $(CFLAGS) -c double_procedures.cpp

mode_parser.o: mode_parser.cpp
	$(CC) $(CFLAGS) -c mode_parser.cpp

color_output.o: color_output.cpp
	$(CC) $(CFLAGS) -c color_output.cpp


run:
	./a.out --help -v --test -s

clean:
	rm a.out

