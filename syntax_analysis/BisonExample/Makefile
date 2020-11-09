OBJS = command.o DiabloExceptions.o
COMPILER = clang++
CFLAGS = -Wc++17-extensions -Wall
OUTPUT = bisonGang

all: scanner parser $(OBJS)
	$(COMPILER) $(CFLAGS) main.cpp $(OBJS) src/maths.cpp src/stack_operations.cpp scanner.cpp parser.cpp interpreter.cpp -o $(OUTPUT)

clean:
	rm -rf scanner.cpp
	rm -rf parser.cpp parser.hpp location.hh position.hh stack.hh
	rm -rf bisonGang
	rm $(OBJS)

scanner: scanner.l
	flex -o scanner.cpp scanner.l

parser: parser.y
	bison -o parser.cpp parser.y


command.o: includes/command.h src/command.cpp
	$(COMPILER) $(CFLAGS) -c src/command.cpp

DiabloExceptions.o: src/DiabloExceptions.cpp includes/DiabloExceptions.hpp
	$(COMPILER) $(CFLAGS) -c src/DiabloExceptions.cpp
